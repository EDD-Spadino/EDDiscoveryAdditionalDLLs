// EDD Interface
#pragma once  

#ifdef _USRDLL 
#define EDD_API __declspec(dllexport)   
#else  
#define EDD_API __declspec(dllimport)   
#endif  


extern "C"
{
#pragma pack(show)
	struct JournalEntry
	{
	public:

		int ver;		// version of this structure. Order critical.
		int indexno;	// event index.  If -1, invalid Journal Entry.  Can happen for EDDRefresh if no history
						// 1 = first entry, to totalrecords

		BSTR utctime;
		BSTR name;
		BSTR info;
		BSTR detailedinfo;
		SAFEARRAY& materials;		// BSTRs in the format name:count
		SAFEARRAY& commodities;		// BSTRs in the format name:count

		BSTR systemname;
		double x;
		double y;
		double z;

		double travelleddistance;
		long travelledseconds;

		bool islanded;
		bool isdocked;

		BSTR whereami;
		BSTR shiptype;
		BSTR gamemode;
		BSTR group;
		long credits;

		BSTR eventid;

		SAFEARRAY& currentmissions;		// BSTRs listing current mission details

		long long jid;					// jid of event
		long totalrecords;				// number of records 
		// Version 1 ends
	};

	// request history.  if isjid=false, 1 = first entry, to end entry.  If isjid=true, its the jid number.
	// Returns true if history entry found, with je set to the journal entry.
	// Returns false if history entry not found, with je set to null
	typedef bool (*EDDRequestHistory)(long index, bool isjid, JournalEntry *je);

	// action a user defined event, of name eventname, thru the EDD event system. Use an EVENT <eventname> statement in your action script
	// to pick the event up and send it to an action program.  You can pass in a list of variables for the action program in the second string
	// use unique names, patterned after your DLL name.  
	// You may issue standard events, but you'll have to make sure all of the multitude of variables are set for other packs to use them properly.
	typedef bool (*EDDRunAction)(BSTR eventname, BSTR parameters); // parameters in format v="k",v2="k" or an empty string

	struct EDDCallBacks
	{
		int ver;			// version of this structure = 1. Order critical.
		EDDRequestHistory RequestHistory;		// may be null - check
		EDDRunAction RunAction;					// may be null - check
		// Version 1 ends
	};

	// Anthing passed in COPY it, don't ref it, c# may remove them after the return at any time.
	// BSTR return values: once passed back, c# owns the BSTR.  It may deallocate at any time.  Best to make a unique copy of the string to pass back.
	
	// Called with EDD version A.B.C.D, return NULL if can't operate, or your version as X.Y.Z.B, or !errorstring to say your unhappy (! indicates error)
	EDD_API BSTR EDDInitialise(BSTR ver, BSTR dllfolder, EDDCallBacks requestcallback);		// mandatory

	EDD_API void EDDRefresh(BSTR cmdr, JournalEntry last_je);			// optional, last_je is the last one received. last_je.indexno =-1 if no history is present.
	EDD_API void EDDNewJournalEntry(JournalEntry nje);		// optional. nje will always be set.  Called when a new Journal Entry received
	EDD_API void EDDTerminate();					// optional
							
	EDD_API BSTR EDDActionCommand(BSTR action, SAFEARRAY& args);		// optional. Called by Action DLLCall. Always return string. Args could be an empty array.
	EDD_API void EDDActionJournalEntry(JournalEntry je);		// optional. Called by Action DLLCall to feed a journal entry to you.
}

