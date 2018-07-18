#if !defined( _CFILE_ANALYSE_H)
#define		_CFILE_ANALYSE_H
/**********************
@ClassFunction

@


**********************/

#include <string>
#include <deque>
#include <map>
#include <list>
#include "DevDef.h"
#include "CXmlResolver.h"
#include <fstream>
//#include <iconv.h>
typedef std::deque<STableInterfaceVar>				VARNODE;
typedef std::map<std::string,std::list<PLCVARTYPE>> USER_VARTYPE;
typedef std::pair<int, std::string> FILE_WITHKIND;
class CFileAnalyse
{
public:

	enum tablekind
	{
		TIA13,
		TIA15
	};
	enum filekind
	{
		//²©Í¾V13
		SCLFILE,
		//²©Í¾V15
		XMLFIILE,
		DBFILE,
		UDTFILE
	};
public:
	CFileAnalyse(void);
	virtual ~CFileAnalyse(void);
	int  FilePathDeal(std::list<std::string> &filegroup,int tablekindflag);
	bool AddFileInfroInTree();
public:
	inline bool getxmldata(std::vector<std::string> &xmldata)
	{
		if (m_nFileKindFlags == TIA13)
		{
			return false;

		}
		xmldata = m_xmldata;
		return true;
	
	
	}
	inline bool getdbdata(std::vector<std::string> &dbdata)
	{
		dbdata = m_dbdata;
		return true;

	
	
	}
	inline bool getudtdata(std::vector<std::string> &udtdata)
	{
		udtdata = m_datatypedata;
		return true;
	
	}
	//inline bool getscldata(std::vector<std::string> &scldata);

private:
	bool FileRead(std::vector<FILE_WITHKIND> & filelist);
	bool ReadDBFile(const std::string &FilePath);
	bool ReadUDTFile(const std::string &FilePath);

	bool ReadDBBlockFile(const std::string &FilePath);
	bool ReadDataTypeFile(const std::string &FilePath);
	bool ReadSCLFile(const std::string &FilePath);
	bool ReadXmlFile(const std::string &FilePath);
	//
	int FiletypeJude(const std::string &fileuffix,int tablekindflag);



private:
	int							m_nFileKindFlags;
	CXmlReSolver				*m_XmlReader;//
	std::vector<FILE_WITHKIND>	m_filelist;
	std::vector<std::string>	m_xmldata;
	std::vector<std::string>	m_dbdata;
	std::vector<std::string>	m_datatypedata;



};
#endif

