#include "stdafx.h"
#include "CXmlResolver.h"
#include <iostream>
CXmlReSolver::CXmlReSolver():m_XmlDoc(new pugi::xml_document)
{


}

CXmlReSolver::~CXmlReSolver()
{
	if (m_XmlDoc!= nullptr)
	{
		delete m_XmlDoc;

	}


}

bool CXmlReSolver::openXmldoc(const std::string &fiepath)
{	

	pugi::xml_parse_result result = m_XmlDoc->load_file(fiepath.c_str(),116,pugi::encoding_utf8);
	if (result.status != pugi::xml_parse_status::status_ok)
		return false;
	return true;
}

bool CXmlReSolver::getattrvaule(const std::vector<std::string> &childnode, const std::string &AttrName, std::string &returnstr)
{	

	//int count = 0;
	//count = child.size();
	pugi::xml_node node;
	node = m_XmlDoc->child(childnode[0].c_str()).child(childnode[1].c_str());//find_child_by_attribute(childnode[0].c_str());
	//node = node.child(childnode[0].c_str());
	if (node == nullptr)
	{
		return false;

	}
	for (; node ; node = node.next_sibling(childnode[1].c_str()))
	{	
		std::cout << (node.attribute("addr").value()) << " _";
		std::cout << (node.attribute("remark").value()) << " _";
		std::cout << (node.attribute("retain").value()) << " _";
		std::cout << (node.attribute("hmiAccessible").value())<< " _";
		std::cout << (node.attribute("hmiWriteable").value()) <<" _";
		std::cout << (node.attribute("hmiVisible").value()) <<" _";
		std::cout << node.first_child().value() <<"_";
		std::cout << (node.attribute(AttrName.c_str()).value())<<std::endl;

	} 
	returnstr = node.attribute(AttrName.c_str()).value();
	//node = m_XmlDoc->next_sibling("Tool");
	return true;
}
