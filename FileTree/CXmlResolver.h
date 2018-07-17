#pragma once
#ifndef _CXMLRESOLVER_H
#define _CXMLRESOLVER_H
//#include "../pugixmllib/pugiconfig.hpp"
#include"../pugixmllib/pugixml.hpp"
#include <vector>
class CXmlReSolver
{
public:
	CXmlReSolver();
	~CXmlReSolver();
public:
	bool openXmldoc(const std::string &fiepath);
	bool getattrvaule(const std::vector<std::string> &childnode,  const std::string &AttrName,std::string &returnstr);


private:
	pugi::xml_document *m_XmlDoc;


};


#endif // !_CXMLRESOLVER_H
