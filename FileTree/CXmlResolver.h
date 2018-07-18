#pragma once
#ifndef _CXMLRESOLVER_H
#define _CXMLRESOLVER_H
#include"../pugixmllib/pugixml.hpp"
#include <vector>
class CXmlReSolver
{
public:
	CXmlReSolver();
	~CXmlReSolver();
public:
	bool openXmldoc(const std::string &fiepath);
	//bool getattrvaule(const std::vector<std::string> &childnode,  const std::string &AttrName,std::string &returnstr);
	bool getXmlattrvaule(const std::string &childnode, const std::string &AttrName, std::vector<std::string> & getattr);

private:
	pugi::xml_document *m_XmlDoc;
public:
	static std::string UTF8_To_string(const std::string & str);


};


#endif // !_CXMLRESOLVER_H
