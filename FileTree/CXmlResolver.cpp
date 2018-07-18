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
/*******************
*功能	UTF8转Unicode字符串
*参数	str UTF-8字符串
*返回值 转换后的Unicode字符串
*
*
*
********************/
bool CXmlReSolver::openXmldoc(const std::string &fiepath)
{	

	pugi::xml_parse_result result = m_XmlDoc->load_file(fiepath.c_str(),116,pugi::encoding_utf8);
	if (result.status != pugi::xml_parse_status::status_ok)
		return false;
	return true;
}

//bool CXmlReSolver::getattrvaule(const std::vector<std::string> &childnode, const std::string &AttrName, std::string &returnstr)
//{	
//
//	//int count = 0;
//	//count = child.size();
//	pugi::xml_node node;
//	node = m_XmlDoc->child(childnode[0].c_str()).child(childnode[1].c_str());//find_child_by_attribute(childnode[0].c_str());
//	//node = node.child(childnode[0].c_str());
//	if (node == nullptr)
//	{
//		return false;
//
//	}
//	for (; node ; node = node.next_sibling(childnode[1].c_str()))
//	{	
//		std::cout << (node.attribute("addr").value()) << " _";
//		std::cout << (node.attribute("remark").value()) << " _";
//		std::cout << (node.attribute("retain").value()) << " _";
//		std::cout << (node.attribute("hmiAccessible").value())<< " _";
//		std::cout << (node.attribute("hmiWriteable").value()) <<" _";
//		std::cout << (node.attribute("hmiVisible").value()) <<" _";
//		std::cout << node.first_child().value() <<"_";
//		std::cout << (node.attribute(AttrName.c_str()).value())<<std::endl;
//
//	} 
//	returnstr = node.attribute(AttrName.c_str()).value();
//	//node = m_XmlDoc->next_sibling("Tool");
//	return true;
//}


/*******************
*功能	UTF8转Unicode字符串
*参数	str UTF-8字符串
*返回值 转换后的Unicode字符串
*
*
*
********************/
bool CXmlReSolver::getXmlattrvaule(const std::string &childnode, const std::string & AttrName, std::vector<std::string> & getattr)
{	
	pugi::xml_node node;
	size_t NodeCount = 0 ;
	std::string firstnode;
	std::string secondnode;
	std::string strline;
	NodeCount = childnode.find("/");
	if (NodeCount!= std::string::npos)
	{
		 firstnode  = childnode.substr(0, NodeCount);
		 secondnode = childnode.substr(NodeCount+1, childnode.length());
	}
	else
	{
		return false;

	}
	node = m_XmlDoc->child(firstnode.c_str()).child(secondnode.c_str());//find_child_by_attribute(childnode[0].c_str());																		 //node = node.child(childnode[0].c_str());
	if (node == nullptr)
	{
		return false;

	}
	for (; node; node = node.next_sibling(secondnode.c_str()))
	{

		strline = strline + node.attribute("addr").value() + ",";
		strline = strline + node.attribute("remark").value() + ",";
		strline = strline + node.attribute("retain").value() + ",";
		strline = strline + node.attribute("hmiAccessible").value() + ",";
		strline = strline + node.attribute("hmiWriteable").value() + ",";
		strline = strline + node.first_child().value() + ",";
		strline = strline + UTF8_To_string(node.attribute(AttrName.c_str()).value());
		getattr.push_back(strline);
		strline.clear();
		


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
std::string CXmlReSolver::UTF8_To_string(const std::string & str)
{
	int nwLen = MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, NULL, 0);

	wchar_t * pwBuf = new wchar_t[nwLen + 1];//一定要加1，不然会出现尾巴 
	memset(pwBuf, 0, nwLen * 2 + 2);

	MultiByteToWideChar(CP_UTF8, 0, str.c_str(), str.length(), pwBuf, nwLen);

	int nLen = WideCharToMultiByte(CP_ACP, 0, pwBuf, -1, NULL, NULL, NULL, NULL);

	char * pBuf = new char[nLen + 1];

	memset(pBuf, 0, nLen + 1);

	WideCharToMultiByte(CP_ACP, 0, pwBuf, nwLen, pBuf, nLen, NULL, NULL);

	std::string retStr = pBuf;

	delete[]pBuf;
	delete[]pwBuf;

	pBuf = NULL;
	pwBuf = NULL;
	return retStr;
}
