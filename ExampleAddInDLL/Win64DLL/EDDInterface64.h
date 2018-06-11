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
		int ver;		// version of this structure = 1. Order critical.
		int indexno;	// event index.  If -1, invalid Journal Entry.  Can happen for EDDRefresh if no history

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
	};

	// Called with EDD version A.B.C.D, return NULL if can't operate, or your version as X.Y.Z.B
	EDD_API BSTR EDDInitialise(BSTR ver);		// mandatory
	EDD_API void EDDRefresh(BSTR cmdr, JournalEntry last_je);			// optional, last_je is the last one received
	EDD_API void EDDNewJournalEntry(JournalEntry nje);		// optional. nje will always be set.  Called when a new Journal Entry received
	EDD_API void EDDTerminate();					// optional

	EDD_API BSTR EDDActionCommand(BSTR action, SAFEARRAY& args);		// optional. If implemented, always return string. Args could be an empty array. Called by Action
	EDD_API void EDDActionJournalEntry(JournalEntry je);		// optional. Called by Action to feed a journal entry to you.
}
