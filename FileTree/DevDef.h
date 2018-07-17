///	DevDef.h
///	设备驱动模版

#if !defined(AFX_DEVDEF_H__INCLUDED_)
#define AFX_DEVDEF_H__INCLUDED_

///	对于PLC中数据类型的定义，有所更改，在此作特作声明如下：
///	以前对于为操作和数据类型用两个属性来表达，现在统一改成
///	用一个属性（数据类型）来表达。但这个值小于80时表示位，
///	当这个值大于等于80时表达数据类型，
///	此时类型值和类型的对应关系如下：
///	80：无符号8位二进制数。
///	81：有符号8位二进制数。
///	82：8位BCD码。
///	83：无符号16位二进制数。
///	84：有符号16位二进制数。
///	85：16位BCD码。
///	86：无符号32位二进制数。
///	87：有符号32位二进制数。
///	88：32位BCD码。
///	89：32位浮点数。
/// 90：字符串
///	100：ASCII表示的浮点数。	


///	此文件用来定义驱动程序中用到的各种常量
///	包括 内部属性页信息 和 DevRow 类的初始化数据

//#include "afxtempl.h"

/////	DEV驱动程序中用到的属性常量定义
/////	帮助ID
//const DWORD		DEV_DWORD_HELPID				= 2102072302;
/////	帮助文件名
//const CString	DEV_STR_HELPFILENAME			= _T("ModbusRTU");
/////	设备名称，即组态搜索设备时显示的名称	
//const CString	DEV_STR_NAME					= _T("莫迪康ModbusRTU");
/////	模拟环境调用的驱动名
//const CString	DEV_STR_DLLNAMEMU				= _T("ModbusRTUEXU.drv");
/////	CE运行环境调用的驱动名
//const CString	DEV_STR_DLLNAMECE				= _T("ModbusRTUEXE.drv");
/////	固定字符串，用于在内部属性页中显示
//const CString	DEV_STR_PAGEADDTILE				= _T("通道属性设置");
/////	固定字符串，用于在删除通道时显示
//const CString	DEV_STR_DELWARNING				= _T("真的要删除所有通道吗？");
/////	固定字符串，串口通讯设备的固有通道
//const CString	DEV_STR_COMMUNICATEFLAG			= _T("通讯状态");
/////	打开块读长度自定义功能的命令
//const CString	DEV_STR_MCGSREADLEN				= _T("MCGSREADLEN");
//const CString	DEV_STR_MCGSREADFAST			= _T("MCGSREADFAST");
/////	十六进制属性值的引导字符
//const CString	DEV_STR_PROPERTYHEAD0X			= _T("0X");
//const CString	DEV_STR_PROPERTYHEADBT			= _T("BT");
///// 通讯状态通道偏移量
//const int		DEV_CHL_OFFSET					= 1;
///// 最大连续数据长度(防治连续添加过长)
//const DWORD		DEV_DWORD_MAXADDRESS			= 5000;
/////	数据的类型基数
//const DWORD		DEV_DWORD_DATATYPEBAS			= 80;
//const DWORD		DEV_DWORD_DATATYPESTR			= 131;//字符串类型
//const CString	DEV_STR_MCGSSTRDATA				= _T("MCGSSTR:");//字符串标识
/////	无类型的数据: 寄存器无数据类型时,可将数据类型设置为此值
//const DWORD		DEV_DWORD_DATATYPENO			= 20;
//
//
//class CDevTable;
//struct MCGS_DATA;
//struct DynBlock;
//typedef CArray<DynBlock,DynBlock&> CDynBlockArray;
//
///// 保存设备信息用的自定义结构，设备编写者在设备初始化中分配，
/////	在设备退出时释放，并负责把MCGS_DATA中的对应指针复位为NULL
//struct DEV_DATA
//{
//	/// 设备属性数组，每一个元素对应基本属性页中的一个属性
//	///	如果是数值型的属性，则这里保存的是属性的值，如果是
//	///	具有下拉框的属性则这里保存的是被选中的下拉框索引。
//	CArray<int, int> nArProperty;
//	
//	/// 保存用户定义的通道信息的指针，Table里面保存的是一个通道数组
//	CDevTable* m_pTable;
//
//	///	原静态分块索引,为流化数据,现已无作用,但为保证流化兼容性,在此保留.
//	CArray<int, int> nArBlockHead;
//	CArray<int, int> nArBlockTail;
//
//	///	扩展属性，最低位用于标志块读长度用户自定义功能是否打开，
//	///	1表示打开，0表示未打开。其它位功能暂时未定
//	/// 第一位用来表示常读属性，1表示打开，0表示未打开
//	int nExtendProperty;
//
//	///	已经读取的块索引，这个成员不用流化
//	int nReadIndex;
//	int nBlockIndex;//分块索引,与nReadIndex配合使用
//
//	/*-------------2009-7-9-------------------*/
//	CArray<int, int> nBlockLen;
//	/*----------------------------------------*/
//
//	//////////驱动日志功能所用/////////////////////////////
//	BOOL bLog;//日志功能标志,1为开启,0为默认不开启
//	BOOL bWriteLog;//是否写日志
//	BOOL bErrLog;//是否为错误日志
//	DWORD dwLogN;//写日志行数
//	CString strLog;//日志字符串
//	DWORD dwLastWriteTime;//前一次写日志的时间2016.2.18 yh
//
//	//////动态计算通讯延时时间及最佳块长所用://////////////
//	float fOneByteTime;//1字节通讯所用时间
//	BOOL bGetPLCTime;//是否正确读取PLC延时等时间
//	int nPLCDelayTime;//PLC实际延时时间
//	float fReadMinTime;//块读最少通讯所用时间
//	int nBlockDataBestNum;//最佳连续读取块长
//	int nMixDataBestNum;//最佳复合读取块长
//	int nBlockParamNum;//每帧最多的参数个数限制(与混合读取块长有关)
//	
//	//////////////动态分块使用/////////////////////////////
//	CArray<int,int> nLastCollectFlag;//存储上次通道采集标志
//	int nCollectDataNum;//采集数据字节数量(非通道数量).
//	int nCollectMixNum;//采集复合数据块数量.
//	int nArBlockNum;//采集块数量.
//	BOOL bMixLogin;//复合登录帧是否正确注册
//	int nMixReadLen;//混合读取要读取的数据长度.
//	CString strMixProtocol;//
//	CDynBlockArray ArDynBlock;
//
//	/////针对没有位操作,按1松0需先读后写时优化所使用////////
//	int nLastAddress;//存储上次通道地址
//	int nLastData;//存储上次通道数据
//	DWORD dwLastTime;//存储上次通道采集时间标志
//	
//    ///////////////主程序版本//////////////////////////////////////////////
//	double lfMcgsVer;//MCGS主程序版本号,标记主程序版本.
//	BOOL bMakeDynBlock;//由主程序控制是否动态分块标志,TRUE为需要动态分块.
//
//	BOOL bIsString;
//};
//
/////	基本属性常量定义开始 //////////////////////////////////
//
/////	基本属性页中自定义属性的数量数量。
/////	如果更改基本属性数量请修改这个常量的值。
//const DWORD		DEV_DWORD_PROPERTYNUM			= 9;   //2009-7-7
//
/////	基本属性索引枚举，可用他代替数值索引访问属性数组。
/////	如果更改基本属性请修改这个结构，枚举值必须从0开始依次递增。
/////	总数量应与属性数量相等。
//enum	DEV_ENUM_PROPERTYNAME
//{
//	DEV_PRO_ADDRESS = 0,
//	DEV_PRO_DELAYTIME = 1,
//	DEV_PRO_FASTTIMES = 2,
//
//	DEV_PRO_16INTCODE = 3,      //16位整数解码顺序
//	DEV_PRO_32INTCODE = 4,      //32位整数解码顺序
//	DEV_PRO_32FLOATCODE = 5,	//32位浮点数解码顺序
//	
//	DEV_PRO_CHECKSTYLE = 6,     //校验方式
//	DEV_PRO_MAKEBLKTYPE = 7,	//分块方式
//	DEV_PRO_FUNCODE = 8,        //4区单字写功能码选择0x06还是0x10
//		
//};
//
/////	基本属性初始值数组，元素数量与属性数量相同，
/////	如过某个属性有下拉列表则其初值为0。
/////	如果更改基本属性请修改这个结构，总数量应与属性数量相等。
//const DWORD		DEV_DWORD_PROPERTYINITVALUE[]	= 
//{
//	1,           //设备地址初始值改为1           2009-7-7
//	200,
//	0,
//
//	0,
//	0,
//	0,
//
//	0,
//	0,
//	0,
//};
//
/////	基本属性名称数组，元素数量与属性数量相同。
/////	如果更改基本属性请修改这个结构，总数量应与属性数量相等。
//const CString	DEV_STR_PROPERTYNAME[]			= 
//{
//	_T("设备地址"),
//	_T("通讯等待时间"),
//	_T("快速采集次数"),
//
//	_T("16位整数解码顺序"),
//	_T("32位整数解码顺序"),
//	_T("32位浮点数解码顺序"),
//
//	_T("校验方式"),
//	_T("分块采集方式"),
//	_T("4区16位写功能码选择"),
//};
//
/////	属性下拉列表中元素数量数组，元素数量与属性数量相同，
/////	其值是对应属性的下拉列表所具有下拉项的数量。
/////	值为0表示该属性没有下拉列表
/////	如果更改基本属性请修改这个结构，总数量应与属性数量相等。
//const DWORD		DEV_DWORD_PROPERTYLISTNUM[]		= 
//{ 	
//	0,
//	0,
//	0,
//	
//	2,
//	4,
//	4,
//
//	2,
//	2,
//	2,
//};
//
/////	属性下拉列表中元素数组，元素数量与属性下拉列表中元素数量数组中所有值的和相同，
/////	这里的值将被按照顺序添加到属性的下拉列表中
//const CString	DEV_STR_PROPERTLIST[]			= 
//{
//	_T("0 - 12"),			//16位整数解码顺序
//	_T("1 - 21"),			
//	
//	_T("0 - 1234"),		//32位整数解码顺序
//	_T("1 - 2143"),		
//	_T("2 - 3412"),		
//	_T("3 - 4321"),		
//							
//	_T("0 - 1234"),		//32位浮点数解码顺序
//	_T("1 - 2143"),		
//	_T("2 - 3412"),		
//	_T("3 - 4321"),		
//	
//	_T("0 - LH[低字节,高字节]"),//校验方式
//	_T("1 - HL[高字节,低字节]"),
//
//	_T("0 - 按最大长度分块"),	  //分块采集方式
//	_T("1 - 按连续地址分块"),
//
//	_T("0 - 0x06"),		 //功能码选择
//	_T("1 - 0x10"),		 
//};
//
/////	基本属性常量定义结束 /////////////////////////////////
//
/////	Grid 控件的常量定义开始 ////////////////////////////// 
/////	网格的行高
//const DWORD		DEV_DWORD_ROW_HEIGHT			= 350;
/////	网格的列数
//const DWORD		DEV_DWORD_COLNUM				= 3;
/////	网格每一列的宽度
//const DWORD		DEV_DWORD_COLWIDTH[]			= 
//{ 
//	800, 
//	2000, 
//	1400,
//};
/////	网格每一列的头文字
//const CString	DEV_STR_COLTITAL[]				= 
//{ 
//	_T("序号"), 
//	_T("设备通道"),
//	_T("读写类型"),
//};
/////	Grid 控件的常量定义结束 //////////////////////////////
//
/////	在PageAddDlg中显示的信息常量定义开始
//const DWORD		DLG_DWORD_PROPERTYNUM			= 6;
//const CString	DLG_STR_001						= _T("寄存器类型:");
//const CString	DLG_STR_002						= _T("数据类型:");
//const CString	DLG_STR_003						= _T("寄存器地址:");
//const CString	DLG_STR_004						= _T("通道数量:");
//const CString	DLG_STR_005						= _T("最大块读字节数:");
//const CString	DLG_STR_006						= _T("字节长度:");      //2009-7-14
//
//const CString	DLG_STR_PROPERTYNAME[]			= 
//{ 
//	DLG_STR_001,  
//	DLG_STR_002,
//	DLG_STR_003,
//	DLG_STR_004,
//	DLG_STR_005,
//	DLG_STR_006,
//};
/////	在PageAddDlg中显示的信息常量定义结束 /////////////////
//
/////	初始化 DevRow 的常量定义开始 /////////////////////////
///// DevRow 用来表示这个设备的一个通道具有什么样的属性
///// 属性数量，根据不同的设备，通常这个数值是不同的，需要修改
//const DWORD		DEVROW_DWORD_PROPERTYNUM		= 8;
/////	各个属性的名称
//const CString	DEVROW_STR_CHLRWFLAG			= _T("通道的读写标志");
//const CString	DEVROW_STR_CHLTYPE				= _T("通道类型");
//const CString	DEVROW_STR_CHLADDRESS			= _T("DEV通道地址");
//const CString	DEVROW_STR_CHLBIT				= _T("通道的位");
//const CString	DEVROW_STR_CHLDATATYPE			= _T("通道的数据类型");
//const CString	DEVROW_STR_CHLREADFASTFLAG		= _T("DEV通道的快读标志");
//const CString	DEVROW_STR_CHLREADMAX			= _T("数据块读的最大长度");
//const CString	DEVROW_STR_CHLNAME				= _T("通道名称");
/////	通道名称数组，使用它的目的是为了能方便地通过名称来访问属性值
//const CString	DEVROW_STR_PROPERTYNAME[]		= 
//{
//	DEVROW_STR_CHLRWFLAG,  
//	DEVROW_STR_CHLTYPE,	
//	DEVROW_STR_CHLADDRESS,
//	DEVROW_STR_CHLBIT,
//	DEVROW_STR_CHLDATATYPE,
//	DEVROW_STR_CHLREADFASTFLAG,
//	DEVROW_STR_CHLREADMAX,
//	DEVROW_STR_CHLNAME,
//};
/////	各个属性的数据类型，1表示DWORD型，2表示CString型，目前只支持这两种数据类型
//const DWORD		DEVROW_DWORD_PROPERTYTYPE[]		= 
//{
//	1, 
//	1,
//	1,
//	1,
//	1,
//	1,
//	1,
//	2,
//};
/////	各个属性是否参与排序，1排序，0不排序，
/////	排序的优先级按照属性在属性名称数组中出现的循序来决定
//const DWORD		DEVROW_DWORD_PROPERTYTAXIS[]	= 
//{ 
//	0, 
//	1,
//	1,
//	1,
//	0,
//	0,
//	0,
//	0,
//};
/////	初始化 DevRow 的常量定义结束 /////////////////////////
//
/////	初始化第一个 Select 框(寄存器类型)的常量定义开始 /////
//
/////	第一个 Select 框的下拉项数量
//const DWORD DEV_DWORD_CHLTYPENUM				= 4;
/////	第一个 Select 框的下拉项的内容
//const CString CHLTYPE_STR_000					= _T("[1区]输入继电器");
//const CString CHLTYPE_STR_001					= _T("[0区]输出继电器");
//const CString CHLTYPE_STR_002					= _T("[3区]输入寄存器");
//const CString CHLTYPE_STR_003					= _T("[4区]输出寄存器");
/////	第一个 Select 框的下拉项的内容数组
//const CString CHLTYPE_STR_PROPERTYNAME[]		= 
//{ 
//	CHLTYPE_STR_000,
//	CHLTYPE_STR_001,
//	CHLTYPE_STR_002,
//	CHLTYPE_STR_003,
//};
/////	初始化第一个 Select 框的常量定义结束 /////////////////
//
/////	初始化第一个 Edit 框的常量定义开始 ///////////////////
//
/////	在第一个 Select 框中选第K项时，Edit 框中会显示这个数组中的第K个元素
/////	如果某个元素的值为"-1"则此时该 Edit 框不起作用，不显示
//const CString	CHLTYPE_STR_EDIT1[]			=      //通道地址
//{ 
//	_T("1"),  
//	_T("1"), 
//	_T("1"), 
//	_T("1"), 
//};
//
/////	初始化第一个 Edit 框的常量定义结束 ///////////////////
//
/////	初始化第二个 Edit 框的常量定义开始 ///////////////////
//
/////	在第一个 Select 框中选第K项时，Edit 框中会显示这个数组中的第K个元素
/////	如果某个元素的值为"-1"则此时该 Edit 框不起作用，不显示
//const CString	CHLTYPE_STR_EDIT2[]			=     //通道数量
//{ 
//	_T("1"),  
//	_T("1"), 
//	_T("1"), 
//	_T("1"), 
//};
//
/////	初始化第二个 Edit 框的常量定义结束 ///////////////////
//
/////	初始化第三个 Edit 框的常量定义开始 ///////////////////
//
/////	在第一个 Select 框中选第K项时，Edit 框中会显示这个数组中的第K个元素
/////	这个输入框是用来控制最大块读长度的，是一个隐藏功能，所以通常不显示。
//const CString	CHLTYPE_STR_EDIT3[]			=   //2009-7-28 修改和DEV_READBLK_MAXNUM值一样了，mfAnalyzeDynBlock函数中分块时直接用pDevData->nBlockLen[i]
//{
//	_T("120"),                //字长
//	_T("120"),                //字长
//	_T("120"),                //字长
//	_T("120"),                //字长
//// 	{_T("320")},                
////	{_T("320")}, 
////	{_T("96")}, 
////	{_T("96")}, 
//};
//
/////	初始化第三个 Edit 框的常量定义结束 ///////////////////
//
/////	初始化可选读写属性设置的常量定义开始 /////////////////
//
/////	在第一个 Select 框中选第K项时，可选的读写属性由第K个元素确定
/////	0为只读，1为只写，2为读写
//const DWORD		CHLTYPE_DWORD_RWFLAG[]		= 
//{
//	0,        //[1区]输入继电器
//	2,        //[0区]输出继电器
//	0,        //[3区]输入寄存器
//	2,        //[4区]输出寄存器
//};
//
/////	初始化可选读写属性设置的常量定义结束 /////////////////
//
/////	初始化第二个 Select 框的设置的常量定义开始 ///////////
//
/////	在第一个 Select 框中选第K项时，
/////	第二个 Select 框中显示内容的项数由第K个元素确定
/////	如果某个元素的值为"0"则此时该 Select 框不起作用，不显示
/////	显示的内容从SELECT2_STR_PROPERTYNAME 数组中按顺序提取
//const DWORD		SELECT2_DWORD_PROPERTYNUM[]		= 
//{
//	{0},        //[1区]输入继电器                         
//	{0},        //[0区]输出继电器
//    {24},        //[3区]输入寄存器
//	{24},        //[4区]输出寄存器
//};
//const CString	SELECT2_STR_PROPERTYNAME[]		= 
//{
//	_T("通道的第00位"),          //[3区]输入寄存器
//	_T("通道的第01位"),
//	_T("通道的第02位"),
//	_T("通道的第03位"),
//	_T("通道的第04位"),
//	_T("通道的第05位"),
//	_T("通道的第06位"),
//	_T("通道的第07位"),
//	_T("通道的第08位"),
//	_T("通道的第09位"),
//	_T("通道的第10位"),
//	_T("通道的第11位"),
//	_T("通道的第12位"),
//	_T("通道的第13位"),
//	_T("通道的第14位"),
//	_T("通道的第15位"),
//	_T("16位 无符号二进制"),    
//	_T("16位 有符号二进制"),
//	_T("16位 4位BCD"),
//	_T("32位 无符号二进制"),
//	_T("32位 有符号二进制"),
//	_T("32位 8位BCD"),
//	_T("32位 浮点数"), 
////	{_T("128字节 字符串")},
//	_T("ASCII字符串"),
//
//	_T("通道的第00位"),         //[4区]输出寄存器
//	_T("通道的第01位"),
//	_T("通道的第02位"),
//	_T("通道的第03位"),
//	_T("通道的第04位"),
//	_T("通道的第05位"),
//	_T("通道的第06位"),
//	_T("通道的第07位"),
//	_T("通道的第08位"),
//	_T("通道的第09位"),
//	_T("通道的第10位"),
//	_T("通道的第11位"),
//	_T("通道的第12位"),
//	_T("通道的第13位"),
//	_T("通道的第14位"),
//	_T("通道的第15位"),
//	_T("16位 无符号二进制"),    
//	_T("16位 有符号二进制"),
//	_T("16位 4位BCD"),
//	_T("32位 无符号二进制"),
//	_T("32位 有符号二进制"),
//	_T("32位 8位BCD"),
//	_T("32位 浮点数"),
////	{_T("128字节 字符串")},
//	_T("ASCII字符串"),
//};
/////	初始化第二个 Select 框的设置的常量定义结束 ///////////
//
///// 串口读写参数枚举量定义开始 ///////////////////////////
//
///// 读写标志枚举:
//enum DEV_RWFLAG 
//{
//	DEV_RWFLAG_READ = 0,	//0-只读
//	DEV_RWFLAG_WRITE = 1,	//1-只写
//	DEV_RWFLAG_RW = 2,		//2-读写
//};
//
///// 校验方向枚举:0-发送加校验,1-接收验证校验
//enum DEV_CHECKDIR 
//{
//	DEV_CHECK_OUT = 0,		//0-发送(加校验)
//	DEV_CHECK_IN = 1,		//1-接收(验证校验)
//};
//
///// 协议收发字符串数据类型枚举:
//enum DEV_PROTOCOLTYPE 
//{
//	DEV_PROTOCOL_ASII = 0,	//0-ASCII码形式
//	DEV_PROTOCOL_HEX = 1,	//1-HEX(16进制)
//};
//
///// 通讯读操作的返回方式枚举:
//enum DEV_COMMSTOPTYPE 
//{
//	DEV_COMM_WAITFORCHAR = 0,	//0-判断截止字符
//	DEV_COMM_WAITFORLEN = 1,	//1-判断长度
//	DEV_COMM_SLEEP = 2,			//2-判断延时
//	DEV_COMM_WAITFORCORL = 3,	//3-满足0或1中的条件
//};
//
///// 通讯命令操作方式枚举:
//enum DEV_RWTYPE 
//{
//	DEV_RWTYPE_READWRITE = 0,		//0-正常读写
//	DEV_RWTYPE_GETPLCTIME = 1,	    //1-获取PLC延时时间
//	DEV_RWTYPE_READ = 2,			//2-正常读取
//	DEV_RWTYPE_WRITE = 3,			//3-正常写入
//};
//
///// 通讯错误返回值枚举:
//enum DEV_COM_ERROR_TYPE 
//{
//	DEV_COM_NOERROR			=  0,//采集正常
//	DEV_COM_INIT_ERROR		= -1,//采集初始化错误
//	DEV_COM_NODATA_ERROR	= -2,//采集无数据返回错误
//	DEV_COM_CHK_ERROR		= -3,//采集数据校验错误
//	DEV_COM_OPER_ERROR		= -4,//读写操作未成功错误
//	DEV_COM_CMD_ERROR		= -5,//命令格式或参数错误
//	DEV_COM_DATA_ERROR		= -6,//数据变量取值或赋值错误
//	DEV_COM_DECODE_ERROR	= -7,//采集数据帧不完整，数据错误
//	DEV_COM_COLLECT_ERROR	= -100,//采集错误,返回信息,只更新通讯状态通道.
//};
//const int DEV_EXCEPTION_BASE	= -1000;
///// 串口读写参数枚举量定义结束 ///////////////////////////
//
///// 数据类型常量定义开始 /////////////////////////////////
///// 用于判断各寄存数据类型,一般不需要修改.
//
/////	内部属性页中在网格控件中显示的读写类型
//const CString	DEV_STR_RWFLAG[]			=
//{
//	_T("只读数据"),
//	_T("只写数据"),
//	_T("读写数据"),
//};
//
/////	各种通道的读写字符，用来组成通道名称的
//const CString	CHLNAME_STR_RWFLAG[]		=
//{
//	_T("只读"),
//	_T("只写"),
//	_T("读写"),
//};
//
/////	各种数据类型的名称字符，用来组成通道名称的
//const CString	DATATYPE_STR_NAME[]			= 
//{ 
//	_T("BUB"),
//	_T("BB"),  
//	_T("BD"),
//	_T("WUB"),
//	_T("WB"),
//	_T("WD"),
//	_T("DUB"),  
//	_T("DB"),
//	_T("DD"),
//	_T("DF"),
//	_T("STR"),//字符串
//};
//
/////	各种数据类型的名称字符，用来查找索引的
//const CString	DATATYPE_STR_SELECT2NAME[]	= 
//{
//	_T("8位 无符号二进制"),
//	_T("8位 有符号二进制"),
//	_T("8位 2位BCD"),
//	_T("16位 无符号二进制"),
//	_T("16位 有符号二进制"),
//	_T("16位 4位BCD"),
//	_T("32位 无符号二进制"),
//	_T("32位 有符号二进制"),
//	_T("32位 8位BCD"),
//	_T("32位 浮点数"),
//	//{_T("128字节 字符串")},
//	_T("ASCII字符串"),
//};
//
/////	各种数据位的名称字符，用来查找索引的
//const CString	DATATYPE_STR_BITNAME[]		= 
//{
//    
//
//	_T("BT00"),
//	_T("BT01"),
//	_T("BT02"),
//	_T("BT03"),
//	_T("BT04"),
//	_T("BT05"),
//	_T("BT06"),
//	_T("BT07"),
//	_T("BT08"),
//	_T("BT09"),
//	_T("BT10"),
//	_T("BT11"),
//	_T("BT12"),
//	_T("BT13"),
//	_T("BT14"),
//	_T("BT15"),
//};
//
/////	各种数据位的名称字符，用来查找索引的
//const CString	DATATYPE_STR_SELECT2BITNAME[]	= 
//{
//	_T("通道的第00位"),
//	_T("通道的第01位"),
//	_T("通道的第02位"),
//	_T("通道的第03位"),
//	_T("通道的第04位"),
//	_T("通道的第05位"),
//	_T("通道的第06位"),
//	_T("通道的第07位"),
//	_T("通道的第08位"),
//	_T("通道的第09位"),
//	_T("通道的第10位"),
//	_T("通道的第11位"),
//	_T("通道的第12位"),
//	_T("通道的第13位"),
//	_T("通道的第14位"),
//	_T("通道的第15位"),
//};
//const int DEV_NODATATYPE	= -1; //与主程序交互时,当没有数据类型时,赋值为-1
///// 数据类型常量定义结束 /////////////////////////////////
//
///// 通道格式化及组帧常量定义开始 /////////////////////////
/////	各种通道的名称字符，用来形成通道名称
//const CString	CHL_STR_NAME[]				= 
//{ 
//	_T("1"),
//	_T("0"),  
//	_T("3"),
//	_T("4"),
//};
//
///// 通道地址在形成通道名中的格式化方式，用于形成通道名
//const CString	DEV_STR_ADDRESSFORMAT[]		=
//{
//	_T("%.4d"),
//	_T("%.4d"),
//	_T("%.4d"),
//	_T("%.4d"),
//};
///// 通道位在形成通道名中的格式化方式，用于形成通道名
//const CString	DEV_STR_BITFORMAT[]			=
//{
//	_T(""),      
//	_T(""),       
//	_T(".%.2d"),     
//	_T(".%.2d"),   
//};
//
/////	各种通道的读写命令字符，即命令码，用于形成读写的通讯帧
//const CString	CHL_STR_READORDER[]				= 
//{ 
//	_T("02"),          //用来读1区
//	_T("01"),          //用来读0区
//	_T("04"),          //用来读3区
//	_T("03"),          //用来读4区
//};
//
/////	各种通道的写命令码，用于形成写的通讯帧
//const CString	CHL_STR_WRITEORDER[]			= 
//{ 
//	_T("00"),          
//	_T("05"),          //用来写0区
//	_T("00"),
//	_T("10"),          //用来写4区
//};
///// 通道格式化及组帧常量定义结束 /////////////////////////
//
///// 动态分块数据帧结构常量定义开始 ///////////////////////
////通讯类型
//enum DEV_FRAM_KIND
//{
//	DEV_FRAME_ONE		= 0,//单帧通讯
//	DEV_FRAME_MANY		= 1,//可多帧通讯
//};
//
////帧类型
//enum DEV_FRAM_TYPE
//{
//	DEV_FRAME1_TYPE		= 0,//单帧或第1帧或结尾帧
//	DEV_FRAME2_TYPE		= 1,//中间帧
//};
//
////写命令类型:0-通道写,此时进行两次操作时间间隔判断,优化按1松0
//enum DEV_WRITE_TYPE
//{
//	DEV_WRITE_CHL		= 0,//通道写
//	DEV_WRITE_BLK		= 1,//块写
//};
//
////动态分块类型:
//enum DEV_DEAL_TYPE
//{
//	DEV_DEAL_NOMIX		= 0,//0-全连续读取
//	DEV_DEAL_ONEMIX		= 1,//1-连续+1个复合块(只有一个复合块)
//	DEV_DEAL_ALLMIX		= 2,//2-全混合读取
//	DEV_DEAL_READCMD	= 3,//3-设备命令读取.
//	DEV_DEAL_WRITECMD	= 4,//4-设备命令写入.
//};
////分块与后块之间的离散阈值: 动态分块时,根据此值进行分块组合
//enum DEV_DYNGRADE_TYPE
//{
//	DEV_DYNGRADE_0	= 0,//未确定,或不进行分块组合
//	DEV_DYNGRADE_1	= 1,//连续
//	DEV_DYNGRADE_2	= 2,//较连续
//	DEV_DYNGRADE_3	= 3,//偏连续
//	DEV_DYNGRADE_4	= 4,//偏离散
//	DEV_DYNGRADE_5	= 5,//较离散
//	DEV_DYNGRADE_6	= 6,//离散
//};
//
///// 处理时:小于nCollectMixNum值为复合块,大于等于nCollectMixNum值为连续块,
/////        nCollectMixNum为0时没有复合块,nCollectMixNum为总块长时全部为混合块.
//const int DEV_DYN_DEALTYPE					= DEV_DEAL_NOMIX;//没有复合读取
/////计算最佳块长
//const BOOL DEV_IFCALC_BESTBLOCK				= TRUE;
//const int DEV_COMM_COSTTIMEMAX1				= 300;//设定连续读取一次通讯花费最长时间
/////PLC等待时间
//const int DEV_PLC_DELAYTIME					= 20;//PLC等待时间
//
//const int DEV_COM_DELAYTIME			= 40;	//串口通讯延时时间(可根据需要延长)
//
///// 数据帧属性
//const int DEV_FRAME1_MAXLEN			= 131;	//第1帧(单帧)最大字节长度
//const int DEV_FRAME2_MAXLEN			= 128;	//第2帧(中间/结尾帧)最大字节长度
//const int DEV_FRAME2_FIXLEN			= 4;	//中间帧固定信息字节长度
//
///// 复合帧或混合读取属性信息(两者不会同时存在)
//const int DEV_MIX_DATAMAXNUM		= 126;	//帧最大数据个数
//const int DEV_MIX_DATABESTNUM		= 46;	//帧最佳数据个数(保证返回时间在约330ms左右)
//// 以下主要用于做长度计算用,可根据需要修改.
//const int DEV_MIXSEND_FIXLEN		= 11;	//帧固定信息字节长度
//const int DEV_MIXSEND_ONEDATALEN	= 11;	//帧每数据(或数据块)信息字节长度	
//const int DEV_MIXREC_FIXLEN			= 13;	//帧固定信息字节长度
//const int DEV_MIXREC_ONEDATALEN		= 5;	//帧每数据信息字节长度
//const int DEV_MIXREC_ONEBLOCKLEN	= 0;	//帧每块数据信息字节长度(混合块使用)
//
//const int DEV_MIXPARA_MAXNUM		= DEV_MIX_DATAMAXNUM;	//混合读取最大参数个数
//const int DEV_MIXPARA_BESTNUM		= DEV_MIX_DATAMAXNUM;	//混合读取最佳参数个数
//
//const int DEV_BLOCK_MAXDATALEN				= 250;
//const int DEV_BLOCK_MINDATALEN				= 30;
/////发送帧为固定长度，接收帧中含数据信息
//const int DEV_BLOCK_MAXLEN                  = 255;  //接收帧的最大长度(字节)
//const int DEV_BLOCK_DATAMAXNUM				= 120;   //帧携带的最大数据个数(继电器和寄存器不一样，具体细节时再改，最多可以读2008个继电器，最多可以读125个寄存器)
//const int DEV_BLOCK_DATABESTNUM				= 115;   //帧最佳数据个数(保证返回时间在约300ms左右，可以读230×8＝1840个继电器，可以读230/2 = 115个寄存器)
//
//const int DEV_BLOCKSEND_FIXLEN				= 8;    //发送帧中固定信息字节长度
//
//const int DEV_BLOCKREC_FIXLEN				= 5;    //接收帧中固定信息字节长度
//const int DEV_BLOCKREC_ONEDATALEN			= 2;   //接收帧中每个数据信息字节长度(继电器和寄存器不一样，具体细节时再改，先按寄存器来算)
//
//const int DEV_BLOCK_BESTSPACE			    = 8;     //读取最佳间隔
///////////////////////////////////////////////////////////////////////////////
//
////连续读取和写入设备命令最大数据个数
////const int DEV_READP_MAXNUM					= 112;
////const int DEV_WRITEP_MAXNUM					= 270;//没用，读写都用的260
//const int DEV_BLOCK_MAXNUM						= 250;
////各寄存器连续读取的最大块长:
//const int DEV_READBLK_MAXNUM[]		= 
//{ 	
//	{120},//1区
//	{120},//0区
//	{120},//3区
//	{120},//4区
//};
////各寄存器连续写入的最大块长:
//const int DEV_WRITEBLK_MAXNUM[]		= 
//{ 
//	{0},//1区只读
//	{120},//0区
//	{0},//3区只读
//	{120},//4区
//};
//
///// MCGS的设备命令定义开始 ///////////////////////////////
//const CString	DEV_STR_READ			= _T("READ");
//const CString	DEV_STR_WRITE			= _T("WRITE");
//const CString	DEV_STR_READ32			= _T("READ32");
//const CString	DEV_STR_WRITE32			= _T("WRITE32");
//const CString	DEV_STR_READP			= _T("READP");
//const CString	DEV_STR_WRITEP			= _T("WRITEP");
//const CString	DEV_STR_READPV			= _T("READPV");
//const CString	DEV_STR_WRITEPV			= _T("WRITEPV");
//const CString	DEV_STR_READBLOCK		= _T("READBLOCK");
//const CString	DEV_STR_WRITEBLOCK		= _T("WRITEBLOCK");
//const CString	DEV_STR_READMUTIREG		= _T("ReadMutiReg");  //读多个寄存器(与旧有驱动兼容)
//const CString	DEV_STR_WRITEMUTIREG	= _T("WriteMutiReg"); //写多个寄存器(与旧有驱动兼容)
////通道写入,单独实现
//const CString	DEV_STR_MCGSWRITE		= _T("MCGS_WRITE");
//
//const CString	DEV_STR_SETHIDDENPRO	= _T("SetHiddenPro");
//const CString	DEV_STR_GETHIDDENPRO	= _T("GetHiddenPro");
//
//const DWORD DEV_DWORD_IOCTRLTYPENUM			= 12;
//const CString IOCTRL_STR_PROPERTYNAME[]		= 
//{
//	DEV_STR_READ,			//0.读取
//	DEV_STR_WRITE,		//1.写入
//	DEV_STR_READ32,		//2.32位数据读取到字符串
//	DEV_STR_WRITE32,		//3.32位数据写入(传入为字符串)
//	DEV_STR_READP,		//4.批量读取
//	DEV_STR_WRITEP,		//5.批量写入
//	DEV_STR_READPV,		//6.批量读取(变量自动累加)
//	DEV_STR_WRITEPV,		//7.批量写入(变量自动累加)
//	DEV_STR_READBLOCK,	//8.批量读取(配方形式块读)
//	DEV_STR_WRITEBLOCK,	//9.批量写入(配方形式块写)
//	DEV_STR_READMUTIREG,	//10.读多个寄存器
//	DEV_STR_WRITEMUTIREG,	//11.读多个寄存器
//};
//
//enum DEV_IOCTRL_TYPE		//需与上面定义同步修改更新
//{
//	DEV_IOCTRL_READ			= 0,//0.读取
//	DEV_IOCTRL_WRITE		= 1,//1.写入
//	DEV_IOCTRL_READ32		= 2,//2.32位数据读取到字符串
//	DEV_IOCTRL_WRITE32		= 3,//3.32位数据写入(传入为字符串)
//	DEV_IOCTRL_READP		= 4,//4.批量读取
//	DEV_IOCTRL_WRITEP		= 5,//5.批量写入
//	DEV_IOCTRL_READPV		= 6,//6.批量读取(变量自动累加)
//	DEV_IOCTRL_WRITEPV		= 7,//7.批量写入(变量自动累加)
//	DEV_IOCTRL_READBLOCK	= 8,//8.批量读取(配方形式块读)
//	DEV_IOCTRL_WRITEBLOCK	= 9,//9.批量写入(配方形式块写)
//	DEV_IOCTRL_READMUTIREG	=10,//10.批量读取到字符串
//	DEV_IOCTRL_WRITEMUTIREG	=11,//11.批量写入从字符串
//};
//
//const int DEV_CMD_MAXNUM		= 512; //读取和写入设备命令最大数据个数(连续)
//const int DEV_CMD_MAXADDRESS	= 65535; //读取和写入设备命令最大地址范围
///// MCGS的设备命令定义结束 ///////////////////////////////
//
/////驱动版本信息,由3位整数，3位小数组成,定义如下:
////1.整数部分对应：大的功能或需求性的变更修改
////2.小数部分对应：BUG修改或小的与原来需求无关的变动
//#define DEV_DOUBLE_VER		   005.012	//驱动版本号,小数点前表示大的改动，小数点后第一位表示定制版本，第二位表示稍大的改动，最后一位表示小改动
//#define DEV_DOUBLE_VEREXT	   0		//扩展版本号(目前未使用)


//PLC标签导入通用数据类型
typedef enum VarType
{
	PLC_BOOL,		//PLC的bool变量，对应一个bit;
	PLC_BYTE,		//PLC的bool变量，对应一个bit;
	PLC_CHAR,		//PLC的bool变量，对应一个bit;
	PLC_WCHAR,		//PLC的bool变量，对应一个bit;
	PLC_SINT,		//PLC的bool变量，对应一个bit;
	PLC_USINT,		//PLC的bool变量，对应一个bit;
	PCL_INT,		//PLC的bool变量，对应一个bit;
	PCL_UINT,		//PLC的bool变量，对应一个bit;
	PLC_DINT,		//PLC的bool变量，对应一个bit;
	PLC_UDINT,		//PLC的bool变量，对应一个bit;
	PLC_WORD,
	PLC_DWORD,
	PLC_LWORD, 

	PLC_REAL,		//PLC的bool变量，对应一个bit;
	PLC_LREAL,

	PLC_S5TIME,
	PLC_TIME,
	PLC_LTIME,

	PLC_DATE,
	PLC_TIME_OF_DATE,
	PLC_LTOD,
	PLC_DATE_AND_TIME,
	PLC_LDT,
	PLC_DTL,

	//博途系统变量
	PLC_IEC_TIMER,
	PLC_IEC_LTIMER,
	PLC_IEC_SCOUNTER,
	PLC_IEC_USCOUNTER,
	PLC_IEC_COUNTER,
	PLC_IEC_UCOUNTER,
	PLC_IEC_DCOUNTER,
	PLC_IEC_UDCOUNTER,
	PLC_IEC_LCOUNTER,
	PLC_IEC_ULCOUNTER,

} PLCVARTYPE;
typedef struct TableInterfaceVar
{
	PLCVARTYPE		 vartype;
	unsigned int	 StartAddress;
	std::string		 RegisterType;
	std::string		 VarName;
	int				 accessFlags ;
	std::string		 Remarks;

}STableInterfaceVar,*PSTableInterfaceVar;
#endif // !defined(AFX_DEVDEF_H__INCLUDED_)