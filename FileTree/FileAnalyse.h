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
typedef std::deque<STableInterfaceVar>			 VARNODE;
typedef std::map<std::string,std::list<PLCVARTYPE>> USER_VARTYPE;
class CFileAnalyse
{
public:
	CFileAnalyse(void);
	virtual ~CFileAnalyse(void);
	bool FileRead(const std::string &FilePath);
	bool AddFileInfroInTree();
private:
	bool ReadExportFile(const std::string &FilePath);
	bool ReadXmlFile(const std::string &FilePath);
private:
	int m_nFileFlags;
	


};
#endif

