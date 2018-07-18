#include "stdafx.h"
#include "FileAnalyse.h"


CFileAnalyse::CFileAnalyse(void):m_XmlReader(new CXmlReSolver),
								 m_nFileKindFlags(0)
{

}
CFileAnalyse::~CFileAnalyse(void)
{
	if (nullptr!= m_XmlReader)
	{
		delete m_XmlReader;
		m_XmlReader = nullptr;
	}



}
/*******************
*功能	UTF8转Unicode字符串
*参数	str UTF-8字符串
*返回值 转换后的Unicode字符串
*
*
*
********************/
bool CFileAnalyse::FileRead(std::vector<FILE_WITHKIND>& filelist)
{
	for (auto i :filelist)
	{
		switch (i.first)
		{
		case XMLFIILE:
		{
			this->ReadXmlFile(i.second);
			break;
		}
		case DBFILE:
		{
			this->ReadDBFile(i.second);
			break;
		}
		case UDTFILE:
		{
			this->ReadUDTFile(i.second);
			break;

		}
		case SCLFILE:
		{
			this->ReadSCLFile(i.second);
			break;

		}
		default:
			return false;
		}
	}


	return true;
}
bool CFileAnalyse::ReadDBFile(const std::string & FilePath)
{
	this->ReadDBBlockFile(FilePath);
	return true;
}
bool CFileAnalyse::ReadUDTFile(const std::string & FilePath)
{	
	this->ReadDataTypeFile(FilePath);
	return false;
}
/*******************
*功能	UTF8转Unicode字符串
*参数	str UTF-8字符串
*返回值 转换后的Unicode字符串
*
*
*
********************/
bool CFileAnalyse::ReadDBBlockFile(const std::string & FilePath)
{	
	bool inputflag = false;
	std::string strtemp;
	std::ifstream dbfile;
	dbfile.open(FilePath);
	while (getline(dbfile,strtemp))
	{
		if (false == inputflag && strtemp.find("DATA_BLOCK")!= std::string::npos )
		{
			inputflag = true;

		}
		if (inputflag)
		{	
			CXmlReSolver::UTF8_To_string(strtemp);
			m_dbdata.push_back(strtemp);
		}
	}
	return false;
}
/*******************
*功能	UTF8转Unicode字符串
*参数	str UTF-8字符串
*返回值 转换后的Unicode字符串
*
*
*
********************/
bool CFileAnalyse::ReadDataTypeFile(const std::string & FilePath)
{
	bool typeunitstart =  false;
	bool typeunitend =  false;
	bool inputflag = false;
	std::string strtemp;
	std::string unitnode;
	std::ifstream dbfile;
	dbfile.open(FilePath);
	//dbfile.seekg(3,std::ios::beg);
	while (getline(dbfile, strtemp))
	{
		if (false == typeunitstart && strtemp.find("TYPE") != std::string::npos)
		{
			typeunitstart = true;

		}
		if (false == typeunitend && strtemp.find("END_TYPE") != std::string::npos)
		{
			typeunitend = true;

		}
		if (typeunitstart)
		{	
			CXmlReSolver::UTF8_To_string(strtemp);
			unitnode = unitnode + strtemp  +  "\r\n";

		}
		if (true == typeunitstart  &&  true == typeunitend)
		{	

			m_datatypedata.push_back(unitnode);
			unitnode.clear();
			bool typeunitstart = false;
			bool typeunitend = false;
		}
	}

	return false;
}
/*******************
*功能	UTF8转Unicode字符串
*参数	str UTF-8字符串
*返回值 转换后的Unicode字符串
*
*
*
********************/
bool CFileAnalyse::ReadSCLFile(const std::string & FilePath)
{
	bool typeunitstart = false;
	bool typeunitend = true;
	bool inputflag = false;
	std::string strtemp;
	std::string unitnode;
	std::ifstream dbfile;
	dbfile.open(FilePath);
	std::getline(dbfile, strtemp);
	if (strtemp.find("DATA_BLOCK") != std::string::npos)
	{
		this->ReadDBBlockFile(FilePath);
	}
	else if (strtemp.find("TYPE") != std::string::npos)
	{
		this->ReadDataTypeFile(FilePath);

	}
	else
	{
		return false;
	}
	return true;
}
/*******************
*功能	UTF8转Unicode字符串
*参数	str UTF-8字符串
*返回值 转换后的Unicode字符串
*
*
*
********************/
bool CFileAnalyse::ReadXmlFile(const std::string & FilePath)
{ 
	this->m_XmlReader->openXmldoc(FilePath);
	this->m_XmlReader->getXmlattrvaule("Tagtable/Tag", "type", m_xmldata);
	return true;
}
int CFileAnalyse::FiletypeJude(const std::string & fileuffix, int tablekindflag)
{
	if (tablekindflag == TIA15)
	{
		if (0 == fileuffix.compare("xml"))
		{
			return XMLFIILE;
		}
		else if (0 == fileuffix.compare("db"))
		{
			return DBFILE;
	
		}
		else if (0 == fileuffix.compare("udt"))
		{
			return UDTFILE;

		}
		else
		{
			return -1;
		}
		
	}
	else if (tablekindflag == TIA13)
	{
		if (0 == fileuffix.compare("scl"))
		{
			return SCLFILE;
		}
		else
		{
			return -1;

		}
	}
	return -1;
}

/*******************
*功能	UTF8转Unicode字符串
*参数	str UTF-8字符串
*返回值 转换后的Unicode字符串
*
*
*
********************/
int  CFileAnalyse::FilePathDeal(std::list<std::string> &filegroup, int tablekindflag)
{	

	m_nFileKindFlags = tablekindflag;
	std::pair<int, std::string> filetype;
	int failcount = 0 ;
	int filecount = filegroup.size();
	std::string filepath;
	int fileflags = 0;
	//先判断文件个数对不对
	if (m_nFileKindFlags == TIA13 && filecount!= 2)
	{
		return false;
	}
	if (m_nFileKindFlags == TIA15 && filecount != 3)
	{
		return false; 

	}
	for (auto &i : filegroup)
	{	
		size_t filekind = 0;
		std::string fileuffix;
		if (std::string::npos != (filekind = i.find(".")))
		{	
			fileuffix = i.substr(filekind+1,i.length());
			fileflags = FiletypeJude(fileuffix, m_nFileKindFlags);
			if (-1 == fileflags)
			{
				return false;

			}
			filetype = std::make_pair(fileflags,i);
			m_filelist.push_back(filetype);
		}
		else
		{

			return false;

		}

	}
	FileRead(m_filelist);
	return  true;

}
/*******************
*功能	UTF8转Unicode字符串
*参数	str UTF-8字符串
*返回值 转换后的Unicode字符串
*
*
*
********************/
bool CFileAnalyse::AddFileInfroInTree()
{
	return false;
}