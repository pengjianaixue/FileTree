#include "stdafx.h"
#include "FileAnalyse.h"
#include <iostream>

int main()
{
	std::vector<std::string> Ret;
	std::vector<std::string> db;
	std::vector<std::string> datatype;
	std::list<std::string> filepath;
	std::string a("D:\\Project\\西门子s1200字符串\\西门子1500标签导入\\博图V15导出文件\\PLCTags.xml");
	filepath.push_back("D:\\Project\\西门子s1200字符串\\西门子1500标签导入\\博图V15导出文件\\PLCTags.xml");
	filepath.push_back("D:\\Project\\西门子s1200字符串\\西门子1500标签导入\\博图V15导出文件\\数据块_2.db");
	filepath.push_back("D:\\Project\\西门子s1200字符串\\西门子1500标签导入\\博图V15导出文件\\用户数据类型_3.udt");

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
	std::cout <<" 数据类型单元计数"<< k << std::endl;
	system("pause");
	
	return   0;



}