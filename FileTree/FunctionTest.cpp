#include "stdafx.h"
#include "FileAnalyse.h"
#include <iostream>

int main()
{
	std::vector<std::string> Ret;
	std::vector<std::string> db;
	std::vector<std::string> datatype;
	std::list<std::string> filepath;
	std::string a("D:\\Project\\������s1200�ַ���\\������1500��ǩ����\\��ͼV15�����ļ�\\PLCTags.xml");
	filepath.push_back("D:\\Project\\������s1200�ַ���\\������1500��ǩ����\\��ͼV15�����ļ�\\PLCTags.xml");
	filepath.push_back("D:\\Project\\������s1200�ַ���\\������1500��ǩ����\\��ͼV15�����ļ�\\���ݿ�_2.db");
	filepath.push_back("D:\\Project\\������s1200�ַ���\\������1500��ǩ����\\��ͼV15�����ļ�\\�û���������_3.udt");

	CFileAnalyse Test;
	Test.FilePathDeal(filepath, CFileAnalyse::TIA15);
	Test.getxmldata(Ret);
	Test.getdbdata(db);
	Test.getudtdata(datatype);
	for (size_t i = 0; i < Ret.size(); ++i)
	{
		std::cout << Ret[i] << std::endl;

	}
	for (auto i: db)
	{

		std::cout << i << std::endl;


	}
	int k = 0;
	for (auto i : datatype)
	{
		++k;
		std::cout << i << std::endl;


	}
	/*CXmlReSolver Test;
	if (Test.openXmldoc(("D:\\ShareFile\\PLCTags.xml")))
	{
		Test.getXmlattrvaule("Tagtable/Tag","type", Ret);
		for (size_t i = 0; i < Ret.size(); ++i)
		{
			std::cout << Ret[i] << std::endl;
		}

	}*/
	std::cout <<" �������͵�Ԫ����"<< k << std::endl;
	system("pause");
	
	return   0;



}