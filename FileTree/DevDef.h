///	DevDef.h
///	�豸����ģ��

#if !defined(AFX_DEVDEF_H__INCLUDED_)
#define AFX_DEVDEF_H__INCLUDED_

///	����PLC���������͵Ķ��壬�������ģ��ڴ��������������£�
///	��ǰ����Ϊ���������������������������������ͳһ�ĳ�
///	��һ�����ԣ��������ͣ�����������ֵС��80ʱ��ʾλ��
///	�����ֵ���ڵ���80ʱ�����������ͣ�
///	��ʱ����ֵ�����͵Ķ�Ӧ��ϵ���£�
///	80���޷���8λ����������
///	81���з���8λ����������
///	82��8λBCD�롣
///	83���޷���16λ����������
///	84���з���16λ����������
///	85��16λBCD�롣
///	86���޷���32λ����������
///	87���з���32λ����������
///	88��32λBCD�롣
///	89��32λ��������
/// 90���ַ���
///	100��ASCII��ʾ�ĸ�������	


///	���ļ��������������������õ��ĸ��ֳ���
///	���� �ڲ�����ҳ��Ϣ �� DevRow ��ĳ�ʼ������

//#include "afxtempl.h"

/////	DEV�����������õ������Գ�������
/////	����ID
//const DWORD		DEV_DWORD_HELPID				= 2102072302;
/////	�����ļ���
//const CString	DEV_STR_HELPFILENAME			= _T("ModbusRTU");
/////	�豸���ƣ�����̬�����豸ʱ��ʾ������	
//const CString	DEV_STR_NAME					= _T("Ī�Ͽ�ModbusRTU");
/////	ģ�⻷�����õ�������
//const CString	DEV_STR_DLLNAMEMU				= _T("ModbusRTUEXU.drv");
/////	CE���л������õ�������
//const CString	DEV_STR_DLLNAMECE				= _T("ModbusRTUEXE.drv");
/////	�̶��ַ������������ڲ�����ҳ����ʾ
//const CString	DEV_STR_PAGEADDTILE				= _T("ͨ����������");
/////	�̶��ַ�����������ɾ��ͨ��ʱ��ʾ
//const CString	DEV_STR_DELWARNING				= _T("���Ҫɾ������ͨ����");
/////	�̶��ַ���������ͨѶ�豸�Ĺ���ͨ��
//const CString	DEV_STR_COMMUNICATEFLAG			= _T("ͨѶ״̬");
/////	�򿪿�������Զ��幦�ܵ�����
//const CString	DEV_STR_MCGSREADLEN				= _T("MCGSREADLEN");
//const CString	DEV_STR_MCGSREADFAST			= _T("MCGSREADFAST");
/////	ʮ����������ֵ�������ַ�
//const CString	DEV_STR_PROPERTYHEAD0X			= _T("0X");
//const CString	DEV_STR_PROPERTYHEADBT			= _T("BT");
///// ͨѶ״̬ͨ��ƫ����
//const int		DEV_CHL_OFFSET					= 1;
///// ����������ݳ���(�����������ӹ���)
//const DWORD		DEV_DWORD_MAXADDRESS			= 5000;
/////	���ݵ����ͻ���
//const DWORD		DEV_DWORD_DATATYPEBAS			= 80;
//const DWORD		DEV_DWORD_DATATYPESTR			= 131;//�ַ�������
//const CString	DEV_STR_MCGSSTRDATA				= _T("MCGSSTR:");//�ַ�����ʶ
/////	�����͵�����: �Ĵ�������������ʱ,�ɽ�������������Ϊ��ֵ
//const DWORD		DEV_DWORD_DATATYPENO			= 20;
//
//
//class CDevTable;
//struct MCGS_DATA;
//struct DynBlock;
//typedef CArray<DynBlock,DynBlock&> CDynBlockArray;
//
///// �����豸��Ϣ�õ��Զ���ṹ���豸��д�����豸��ʼ���з��䣬
/////	���豸�˳�ʱ�ͷţ��������MCGS_DATA�еĶ�Ӧָ�븴λΪNULL
//struct DEV_DATA
//{
//	/// �豸�������飬ÿһ��Ԫ�ض�Ӧ��������ҳ�е�һ������
//	///	�������ֵ�͵����ԣ������ﱣ��������Ե�ֵ�������
//	///	��������������������ﱣ����Ǳ�ѡ�е�������������
//	CArray<int, int> nArProperty;
//	
//	/// �����û������ͨ����Ϣ��ָ�룬Table���汣�����һ��ͨ������
//	CDevTable* m_pTable;
//
//	///	ԭ��̬�ֿ�����,Ϊ��������,����������,��Ϊ��֤����������,�ڴ˱���.
//	CArray<int, int> nArBlockHead;
//	CArray<int, int> nArBlockTail;
//
//	///	��չ���ԣ����λ���ڱ�־��������û��Զ��幦���Ƿ�򿪣�
//	///	1��ʾ�򿪣�0��ʾδ�򿪡�����λ������ʱδ��
//	/// ��һλ������ʾ�������ԣ�1��ʾ�򿪣�0��ʾδ��
//	int nExtendProperty;
//
//	///	�Ѿ���ȡ�Ŀ������������Ա��������
//	int nReadIndex;
//	int nBlockIndex;//�ֿ�����,��nReadIndex���ʹ��
//
//	/*-------------2009-7-9-------------------*/
//	CArray<int, int> nBlockLen;
//	/*----------------------------------------*/
//
//	//////////������־��������/////////////////////////////
//	BOOL bLog;//��־���ܱ�־,1Ϊ����,0ΪĬ�ϲ�����
//	BOOL bWriteLog;//�Ƿ�д��־
//	BOOL bErrLog;//�Ƿ�Ϊ������־
//	DWORD dwLogN;//д��־����
//	CString strLog;//��־�ַ���
//	DWORD dwLastWriteTime;//ǰһ��д��־��ʱ��2016.2.18 yh
//
//	//////��̬����ͨѶ��ʱʱ�估��ѿ鳤����://////////////
//	float fOneByteTime;//1�ֽ�ͨѶ����ʱ��
//	BOOL bGetPLCTime;//�Ƿ���ȷ��ȡPLC��ʱ��ʱ��
//	int nPLCDelayTime;//PLCʵ����ʱʱ��
//	float fReadMinTime;//�������ͨѶ����ʱ��
//	int nBlockDataBestNum;//���������ȡ�鳤
//	int nMixDataBestNum;//��Ѹ��϶�ȡ�鳤
//	int nBlockParamNum;//ÿ֡���Ĳ�����������(���϶�ȡ�鳤�й�)
//	
//	//////////////��̬�ֿ�ʹ��/////////////////////////////
//	CArray<int,int> nLastCollectFlag;//�洢�ϴ�ͨ���ɼ���־
//	int nCollectDataNum;//�ɼ������ֽ�����(��ͨ������).
//	int nCollectMixNum;//�ɼ��������ݿ�����.
//	int nArBlockNum;//�ɼ�������.
//	BOOL bMixLogin;//���ϵ�¼֡�Ƿ���ȷע��
//	int nMixReadLen;//��϶�ȡҪ��ȡ�����ݳ���.
//	CString strMixProtocol;//
//	CDynBlockArray ArDynBlock;
//
//	/////���û��λ����,��1��0���ȶ���дʱ�Ż���ʹ��////////
//	int nLastAddress;//�洢�ϴ�ͨ����ַ
//	int nLastData;//�洢�ϴ�ͨ������
//	DWORD dwLastTime;//�洢�ϴ�ͨ���ɼ�ʱ���־
//	
//    ///////////////������汾//////////////////////////////////////////////
//	double lfMcgsVer;//MCGS������汾��,���������汾.
//	BOOL bMakeDynBlock;//������������Ƿ�̬�ֿ��־,TRUEΪ��Ҫ��̬�ֿ�.
//
//	BOOL bIsString;
//};
//
/////	�������Գ������忪ʼ //////////////////////////////////
//
/////	��������ҳ���Զ������Ե�����������
/////	������Ļ��������������޸����������ֵ��
//const DWORD		DEV_DWORD_PROPERTYNUM			= 9;   //2009-7-7
//
/////	������������ö�٣�������������ֵ���������������顣
/////	������Ļ����������޸�����ṹ��ö��ֵ�����0��ʼ���ε�����
/////	������Ӧ������������ȡ�
//enum	DEV_ENUM_PROPERTYNAME
//{
//	DEV_PRO_ADDRESS = 0,
//	DEV_PRO_DELAYTIME = 1,
//	DEV_PRO_FASTTIMES = 2,
//
//	DEV_PRO_16INTCODE = 3,      //16λ��������˳��
//	DEV_PRO_32INTCODE = 4,      //32λ��������˳��
//	DEV_PRO_32FLOATCODE = 5,	//32λ����������˳��
//	
//	DEV_PRO_CHECKSTYLE = 6,     //У�鷽ʽ
//	DEV_PRO_MAKEBLKTYPE = 7,	//�ֿ鷽ʽ
//	DEV_PRO_FUNCODE = 8,        //4������д������ѡ��0x06����0x10
//		
//};
//
/////	�������Գ�ʼֵ���飬Ԫ������������������ͬ��
/////	���ĳ�������������б������ֵΪ0��
/////	������Ļ����������޸�����ṹ��������Ӧ������������ȡ�
//const DWORD		DEV_DWORD_PROPERTYINITVALUE[]	= 
//{
//	1,           //�豸��ַ��ʼֵ��Ϊ1           2009-7-7
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
/////	���������������飬Ԫ������������������ͬ��
/////	������Ļ����������޸�����ṹ��������Ӧ������������ȡ�
//const CString	DEV_STR_PROPERTYNAME[]			= 
//{
//	_T("�豸��ַ"),
//	_T("ͨѶ�ȴ�ʱ��"),
//	_T("���ٲɼ�����"),
//
//	_T("16λ��������˳��"),
//	_T("32λ��������˳��"),
//	_T("32λ����������˳��"),
//
//	_T("У�鷽ʽ"),
//	_T("�ֿ�ɼ���ʽ"),
//	_T("4��16λд������ѡ��"),
//};
//
/////	���������б���Ԫ���������飬Ԫ������������������ͬ��
/////	��ֵ�Ƕ�Ӧ���Ե������б��������������������
/////	ֵΪ0��ʾ������û�������б�
/////	������Ļ����������޸�����ṹ��������Ӧ������������ȡ�
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
/////	���������б���Ԫ�����飬Ԫ�����������������б���Ԫ����������������ֵ�ĺ���ͬ��
/////	�����ֵ��������˳�����ӵ����Ե������б���
//const CString	DEV_STR_PROPERTLIST[]			= 
//{
//	_T("0 - 12"),			//16λ��������˳��
//	_T("1 - 21"),			
//	
//	_T("0 - 1234"),		//32λ��������˳��
//	_T("1 - 2143"),		
//	_T("2 - 3412"),		
//	_T("3 - 4321"),		
//							
//	_T("0 - 1234"),		//32λ����������˳��
//	_T("1 - 2143"),		
//	_T("2 - 3412"),		
//	_T("3 - 4321"),		
//	
//	_T("0 - LH[���ֽ�,���ֽ�]"),//У�鷽ʽ
//	_T("1 - HL[���ֽ�,���ֽ�]"),
//
//	_T("0 - ����󳤶ȷֿ�"),	  //�ֿ�ɼ���ʽ
//	_T("1 - ��������ַ�ֿ�"),
//
//	_T("0 - 0x06"),		 //������ѡ��
//	_T("1 - 0x10"),		 
//};
//
/////	�������Գ���������� /////////////////////////////////
//
/////	Grid �ؼ��ĳ������忪ʼ ////////////////////////////// 
/////	������и�
//const DWORD		DEV_DWORD_ROW_HEIGHT			= 350;
/////	���������
//const DWORD		DEV_DWORD_COLNUM				= 3;
/////	����ÿһ�еĿ���
//const DWORD		DEV_DWORD_COLWIDTH[]			= 
//{ 
//	800, 
//	2000, 
//	1400,
//};
/////	����ÿһ�е�ͷ����
//const CString	DEV_STR_COLTITAL[]				= 
//{ 
//	_T("���"), 
//	_T("�豸ͨ��"),
//	_T("��д����"),
//};
/////	Grid �ؼ��ĳ���������� //////////////////////////////
//
/////	��PageAddDlg����ʾ����Ϣ�������忪ʼ
//const DWORD		DLG_DWORD_PROPERTYNUM			= 6;
//const CString	DLG_STR_001						= _T("�Ĵ�������:");
//const CString	DLG_STR_002						= _T("��������:");
//const CString	DLG_STR_003						= _T("�Ĵ�����ַ:");
//const CString	DLG_STR_004						= _T("ͨ������:");
//const CString	DLG_STR_005						= _T("������ֽ���:");
//const CString	DLG_STR_006						= _T("�ֽڳ���:");      //2009-7-14
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
/////	��PageAddDlg����ʾ����Ϣ����������� /////////////////
//
/////	��ʼ�� DevRow �ĳ������忪ʼ /////////////////////////
///// DevRow ������ʾ����豸��һ��ͨ������ʲô��������
///// �������������ݲ�ͬ���豸��ͨ�������ֵ�ǲ�ͬ�ģ���Ҫ�޸�
//const DWORD		DEVROW_DWORD_PROPERTYNUM		= 8;
/////	�������Ե�����
//const CString	DEVROW_STR_CHLRWFLAG			= _T("ͨ���Ķ�д��־");
//const CString	DEVROW_STR_CHLTYPE				= _T("ͨ������");
//const CString	DEVROW_STR_CHLADDRESS			= _T("DEVͨ����ַ");
//const CString	DEVROW_STR_CHLBIT				= _T("ͨ����λ");
//const CString	DEVROW_STR_CHLDATATYPE			= _T("ͨ������������");
//const CString	DEVROW_STR_CHLREADFASTFLAG		= _T("DEVͨ���Ŀ����־");
//const CString	DEVROW_STR_CHLREADMAX			= _T("���ݿ������󳤶�");
//const CString	DEVROW_STR_CHLNAME				= _T("ͨ������");
/////	ͨ���������飬ʹ������Ŀ����Ϊ���ܷ����ͨ����������������ֵ
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
/////	�������Ե��������ͣ�1��ʾDWORD�ͣ�2��ʾCString�ͣ�Ŀǰֻ֧����������������
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
/////	���������Ƿ��������1����0������
/////	��������ȼ������������������������г��ֵ�ѭ��������
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
/////	��ʼ�� DevRow �ĳ���������� /////////////////////////
//
/////	��ʼ����һ�� Select ��(�Ĵ�������)�ĳ������忪ʼ /////
//
/////	��һ�� Select �������������
//const DWORD DEV_DWORD_CHLTYPENUM				= 4;
/////	��һ�� Select ��������������
//const CString CHLTYPE_STR_000					= _T("[1��]����̵���");
//const CString CHLTYPE_STR_001					= _T("[0��]����̵���");
//const CString CHLTYPE_STR_002					= _T("[3��]����Ĵ���");
//const CString CHLTYPE_STR_003					= _T("[4��]����Ĵ���");
/////	��һ�� Select ������������������
//const CString CHLTYPE_STR_PROPERTYNAME[]		= 
//{ 
//	CHLTYPE_STR_000,
//	CHLTYPE_STR_001,
//	CHLTYPE_STR_002,
//	CHLTYPE_STR_003,
//};
/////	��ʼ����һ�� Select ��ĳ���������� /////////////////
//
/////	��ʼ����һ�� Edit ��ĳ������忪ʼ ///////////////////
//
/////	�ڵ�һ�� Select ����ѡ��K��ʱ��Edit ���л���ʾ��������еĵ�K��Ԫ��
/////	���ĳ��Ԫ�ص�ֵΪ"-1"���ʱ�� Edit �������ã�����ʾ
//const CString	CHLTYPE_STR_EDIT1[]			=      //ͨ����ַ
//{ 
//	_T("1"),  
//	_T("1"), 
//	_T("1"), 
//	_T("1"), 
//};
//
/////	��ʼ����һ�� Edit ��ĳ���������� ///////////////////
//
/////	��ʼ���ڶ��� Edit ��ĳ������忪ʼ ///////////////////
//
/////	�ڵ�һ�� Select ����ѡ��K��ʱ��Edit ���л���ʾ��������еĵ�K��Ԫ��
/////	���ĳ��Ԫ�ص�ֵΪ"-1"���ʱ�� Edit �������ã�����ʾ
//const CString	CHLTYPE_STR_EDIT2[]			=     //ͨ������
//{ 
//	_T("1"),  
//	_T("1"), 
//	_T("1"), 
//	_T("1"), 
//};
//
/////	��ʼ���ڶ��� Edit ��ĳ���������� ///////////////////
//
/////	��ʼ�������� Edit ��ĳ������忪ʼ ///////////////////
//
/////	�ڵ�һ�� Select ����ѡ��K��ʱ��Edit ���л���ʾ��������еĵ�K��Ԫ��
/////	��������������������������ȵģ���һ�����ع��ܣ�����ͨ������ʾ��
//const CString	CHLTYPE_STR_EDIT3[]			=   //2009-7-28 �޸ĺ�DEV_READBLK_MAXNUMֵһ���ˣ�mfAnalyzeDynBlock�����зֿ�ʱֱ����pDevData->nBlockLen[i]
//{
//	_T("120"),                //�ֳ�
//	_T("120"),                //�ֳ�
//	_T("120"),                //�ֳ�
//	_T("120"),                //�ֳ�
//// 	{_T("320")},                
////	{_T("320")}, 
////	{_T("96")}, 
////	{_T("96")}, 
//};
//
/////	��ʼ�������� Edit ��ĳ���������� ///////////////////
//
/////	��ʼ����ѡ��д�������õĳ������忪ʼ /////////////////
//
/////	�ڵ�һ�� Select ����ѡ��K��ʱ����ѡ�Ķ�д�����ɵ�K��Ԫ��ȷ��
/////	0Ϊֻ����1Ϊֻд��2Ϊ��д
//const DWORD		CHLTYPE_DWORD_RWFLAG[]		= 
//{
//	0,        //[1��]����̵���
//	2,        //[0��]����̵���
//	0,        //[3��]����Ĵ���
//	2,        //[4��]����Ĵ���
//};
//
/////	��ʼ����ѡ��д�������õĳ���������� /////////////////
//
/////	��ʼ���ڶ��� Select ������õĳ������忪ʼ ///////////
//
/////	�ڵ�һ�� Select ����ѡ��K��ʱ��
/////	�ڶ��� Select ������ʾ���ݵ������ɵ�K��Ԫ��ȷ��
/////	���ĳ��Ԫ�ص�ֵΪ"0"���ʱ�� Select �������ã�����ʾ
/////	��ʾ�����ݴ�SELECT2_STR_PROPERTYNAME �����а�˳����ȡ
//const DWORD		SELECT2_DWORD_PROPERTYNUM[]		= 
//{
//	{0},        //[1��]����̵���                         
//	{0},        //[0��]����̵���
//    {24},        //[3��]����Ĵ���
//	{24},        //[4��]����Ĵ���
//};
//const CString	SELECT2_STR_PROPERTYNAME[]		= 
//{
//	_T("ͨ���ĵ�00λ"),          //[3��]����Ĵ���
//	_T("ͨ���ĵ�01λ"),
//	_T("ͨ���ĵ�02λ"),
//	_T("ͨ���ĵ�03λ"),
//	_T("ͨ���ĵ�04λ"),
//	_T("ͨ���ĵ�05λ"),
//	_T("ͨ���ĵ�06λ"),
//	_T("ͨ���ĵ�07λ"),
//	_T("ͨ���ĵ�08λ"),
//	_T("ͨ���ĵ�09λ"),
//	_T("ͨ���ĵ�10λ"),
//	_T("ͨ���ĵ�11λ"),
//	_T("ͨ���ĵ�12λ"),
//	_T("ͨ���ĵ�13λ"),
//	_T("ͨ���ĵ�14λ"),
//	_T("ͨ���ĵ�15λ"),
//	_T("16λ �޷��Ŷ�����"),    
//	_T("16λ �з��Ŷ�����"),
//	_T("16λ 4λBCD"),
//	_T("32λ �޷��Ŷ�����"),
//	_T("32λ �з��Ŷ�����"),
//	_T("32λ 8λBCD"),
//	_T("32λ ������"), 
////	{_T("128�ֽ� �ַ���")},
//	_T("ASCII�ַ���"),
//
//	_T("ͨ���ĵ�00λ"),         //[4��]����Ĵ���
//	_T("ͨ���ĵ�01λ"),
//	_T("ͨ���ĵ�02λ"),
//	_T("ͨ���ĵ�03λ"),
//	_T("ͨ���ĵ�04λ"),
//	_T("ͨ���ĵ�05λ"),
//	_T("ͨ���ĵ�06λ"),
//	_T("ͨ���ĵ�07λ"),
//	_T("ͨ���ĵ�08λ"),
//	_T("ͨ���ĵ�09λ"),
//	_T("ͨ���ĵ�10λ"),
//	_T("ͨ���ĵ�11λ"),
//	_T("ͨ���ĵ�12λ"),
//	_T("ͨ���ĵ�13λ"),
//	_T("ͨ���ĵ�14λ"),
//	_T("ͨ���ĵ�15λ"),
//	_T("16λ �޷��Ŷ�����"),    
//	_T("16λ �з��Ŷ�����"),
//	_T("16λ 4λBCD"),
//	_T("32λ �޷��Ŷ�����"),
//	_T("32λ �з��Ŷ�����"),
//	_T("32λ 8λBCD"),
//	_T("32λ ������"),
////	{_T("128�ֽ� �ַ���")},
//	_T("ASCII�ַ���"),
//};
/////	��ʼ���ڶ��� Select ������õĳ���������� ///////////
//
///// ���ڶ�д����ö�������忪ʼ ///////////////////////////
//
///// ��д��־ö��:
//enum DEV_RWFLAG 
//{
//	DEV_RWFLAG_READ = 0,	//0-ֻ��
//	DEV_RWFLAG_WRITE = 1,	//1-ֻд
//	DEV_RWFLAG_RW = 2,		//2-��д
//};
//
///// У�鷽��ö��:0-���ͼ�У��,1-������֤У��
//enum DEV_CHECKDIR 
//{
//	DEV_CHECK_OUT = 0,		//0-����(��У��)
//	DEV_CHECK_IN = 1,		//1-����(��֤У��)
//};
//
///// Э���շ��ַ�����������ö��:
//enum DEV_PROTOCOLTYPE 
//{
//	DEV_PROTOCOL_ASII = 0,	//0-ASCII����ʽ
//	DEV_PROTOCOL_HEX = 1,	//1-HEX(16����)
//};
//
///// ͨѶ�������ķ��ط�ʽö��:
//enum DEV_COMMSTOPTYPE 
//{
//	DEV_COMM_WAITFORCHAR = 0,	//0-�жϽ�ֹ�ַ�
//	DEV_COMM_WAITFORLEN = 1,	//1-�жϳ���
//	DEV_COMM_SLEEP = 2,			//2-�ж���ʱ
//	DEV_COMM_WAITFORCORL = 3,	//3-����0��1�е�����
//};
//
///// ͨѶ���������ʽö��:
//enum DEV_RWTYPE 
//{
//	DEV_RWTYPE_READWRITE = 0,		//0-������д
//	DEV_RWTYPE_GETPLCTIME = 1,	    //1-��ȡPLC��ʱʱ��
//	DEV_RWTYPE_READ = 2,			//2-������ȡ
//	DEV_RWTYPE_WRITE = 3,			//3-����д��
//};
//
///// ͨѶ���󷵻�ֵö��:
//enum DEV_COM_ERROR_TYPE 
//{
//	DEV_COM_NOERROR			=  0,//�ɼ�����
//	DEV_COM_INIT_ERROR		= -1,//�ɼ���ʼ������
//	DEV_COM_NODATA_ERROR	= -2,//�ɼ������ݷ��ش���
//	DEV_COM_CHK_ERROR		= -3,//�ɼ�����У�����
//	DEV_COM_OPER_ERROR		= -4,//��д����δ�ɹ�����
//	DEV_COM_CMD_ERROR		= -5,//�����ʽ���������
//	DEV_COM_DATA_ERROR		= -6,//���ݱ���ȡֵ��ֵ����
//	DEV_COM_DECODE_ERROR	= -7,//�ɼ�����֡�����������ݴ���
//	DEV_COM_COLLECT_ERROR	= -100,//�ɼ�����,������Ϣ,ֻ����ͨѶ״̬ͨ��.
//};
//const int DEV_EXCEPTION_BASE	= -1000;
///// ���ڶ�д����ö����������� ///////////////////////////
//
///// �������ͳ������忪ʼ /////////////////////////////////
///// �����жϸ��Ĵ���������,һ�㲻��Ҫ�޸�.
//
/////	�ڲ�����ҳ��������ؼ�����ʾ�Ķ�д����
//const CString	DEV_STR_RWFLAG[]			=
//{
//	_T("ֻ������"),
//	_T("ֻд����"),
//	_T("��д����"),
//};
//
/////	����ͨ���Ķ�д�ַ����������ͨ�����Ƶ�
//const CString	CHLNAME_STR_RWFLAG[]		=
//{
//	_T("ֻ��"),
//	_T("ֻд"),
//	_T("��д"),
//};
//
/////	�����������͵������ַ����������ͨ�����Ƶ�
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
//	_T("STR"),//�ַ���
//};
//
/////	�����������͵������ַ�����������������
//const CString	DATATYPE_STR_SELECT2NAME[]	= 
//{
//	_T("8λ �޷��Ŷ�����"),
//	_T("8λ �з��Ŷ�����"),
//	_T("8λ 2λBCD"),
//	_T("16λ �޷��Ŷ�����"),
//	_T("16λ �з��Ŷ�����"),
//	_T("16λ 4λBCD"),
//	_T("32λ �޷��Ŷ�����"),
//	_T("32λ �з��Ŷ�����"),
//	_T("32λ 8λBCD"),
//	_T("32λ ������"),
//	//{_T("128�ֽ� �ַ���")},
//	_T("ASCII�ַ���"),
//};
//
/////	��������λ�������ַ�����������������
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
/////	��������λ�������ַ�����������������
//const CString	DATATYPE_STR_SELECT2BITNAME[]	= 
//{
//	_T("ͨ���ĵ�00λ"),
//	_T("ͨ���ĵ�01λ"),
//	_T("ͨ���ĵ�02λ"),
//	_T("ͨ���ĵ�03λ"),
//	_T("ͨ���ĵ�04λ"),
//	_T("ͨ���ĵ�05λ"),
//	_T("ͨ���ĵ�06λ"),
//	_T("ͨ���ĵ�07λ"),
//	_T("ͨ���ĵ�08λ"),
//	_T("ͨ���ĵ�09λ"),
//	_T("ͨ���ĵ�10λ"),
//	_T("ͨ���ĵ�11λ"),
//	_T("ͨ���ĵ�12λ"),
//	_T("ͨ���ĵ�13λ"),
//	_T("ͨ���ĵ�14λ"),
//	_T("ͨ���ĵ�15λ"),
//};
//const int DEV_NODATATYPE	= -1; //�������򽻻�ʱ,��û����������ʱ,��ֵΪ-1
///// �������ͳ���������� /////////////////////////////////
//
///// ͨ����ʽ������֡�������忪ʼ /////////////////////////
/////	����ͨ���������ַ��������γ�ͨ������
//const CString	CHL_STR_NAME[]				= 
//{ 
//	_T("1"),
//	_T("0"),  
//	_T("3"),
//	_T("4"),
//};
//
///// ͨ����ַ���γ�ͨ�����еĸ�ʽ����ʽ�������γ�ͨ����
//const CString	DEV_STR_ADDRESSFORMAT[]		=
//{
//	_T("%.4d"),
//	_T("%.4d"),
//	_T("%.4d"),
//	_T("%.4d"),
//};
///// ͨ��λ���γ�ͨ�����еĸ�ʽ����ʽ�������γ�ͨ����
//const CString	DEV_STR_BITFORMAT[]			=
//{
//	_T(""),      
//	_T(""),       
//	_T(".%.2d"),     
//	_T(".%.2d"),   
//};
//
/////	����ͨ���Ķ�д�����ַ����������룬�����γɶ�д��ͨѶ֡
//const CString	CHL_STR_READORDER[]				= 
//{ 
//	_T("02"),          //������1��
//	_T("01"),          //������0��
//	_T("04"),          //������3��
//	_T("03"),          //������4��
//};
//
/////	����ͨ����д�����룬�����γ�д��ͨѶ֡
//const CString	CHL_STR_WRITEORDER[]			= 
//{ 
//	_T("00"),          
//	_T("05"),          //����д0��
//	_T("00"),
//	_T("10"),          //����д4��
//};
///// ͨ����ʽ������֡����������� /////////////////////////
//
///// ��̬�ֿ�����֡�ṹ�������忪ʼ ///////////////////////
////ͨѶ����
//enum DEV_FRAM_KIND
//{
//	DEV_FRAME_ONE		= 0,//��֡ͨѶ
//	DEV_FRAME_MANY		= 1,//�ɶ�֡ͨѶ
//};
//
////֡����
//enum DEV_FRAM_TYPE
//{
//	DEV_FRAME1_TYPE		= 0,//��֡���1֡���β֡
//	DEV_FRAME2_TYPE		= 1,//�м�֡
//};
//
////д��������:0-ͨ��д,��ʱ�������β���ʱ�����ж�,�Ż���1��0
//enum DEV_WRITE_TYPE
//{
//	DEV_WRITE_CHL		= 0,//ͨ��д
//	DEV_WRITE_BLK		= 1,//��д
//};
//
////��̬�ֿ�����:
//enum DEV_DEAL_TYPE
//{
//	DEV_DEAL_NOMIX		= 0,//0-ȫ������ȡ
//	DEV_DEAL_ONEMIX		= 1,//1-����+1�����Ͽ�(ֻ��һ�����Ͽ�)
//	DEV_DEAL_ALLMIX		= 2,//2-ȫ��϶�ȡ
//	DEV_DEAL_READCMD	= 3,//3-�豸�����ȡ.
//	DEV_DEAL_WRITECMD	= 4,//4-�豸����д��.
//};
////�ֿ�����֮�����ɢ��ֵ: ��̬�ֿ�ʱ,���ݴ�ֵ���зֿ����
//enum DEV_DYNGRADE_TYPE
//{
//	DEV_DYNGRADE_0	= 0,//δȷ��,�򲻽��зֿ����
//	DEV_DYNGRADE_1	= 1,//����
//	DEV_DYNGRADE_2	= 2,//������
//	DEV_DYNGRADE_3	= 3,//ƫ����
//	DEV_DYNGRADE_4	= 4,//ƫ��ɢ
//	DEV_DYNGRADE_5	= 5,//����ɢ
//	DEV_DYNGRADE_6	= 6,//��ɢ
//};
//
///// ����ʱ:С��nCollectMixNumֵΪ���Ͽ�,���ڵ���nCollectMixNumֵΪ������,
/////        nCollectMixNumΪ0ʱû�и��Ͽ�,nCollectMixNumΪ�ܿ鳤ʱȫ��Ϊ��Ͽ�.
//const int DEV_DYN_DEALTYPE					= DEV_DEAL_NOMIX;//û�и��϶�ȡ
/////������ѿ鳤
//const BOOL DEV_IFCALC_BESTBLOCK				= TRUE;
//const int DEV_COMM_COSTTIMEMAX1				= 300;//�趨������ȡһ��ͨѶ�����ʱ��
/////PLC�ȴ�ʱ��
//const int DEV_PLC_DELAYTIME					= 20;//PLC�ȴ�ʱ��
//
//const int DEV_COM_DELAYTIME			= 40;	//����ͨѶ��ʱʱ��(�ɸ�����Ҫ�ӳ�)
//
///// ����֡����
//const int DEV_FRAME1_MAXLEN			= 131;	//��1֡(��֡)����ֽڳ���
//const int DEV_FRAME2_MAXLEN			= 128;	//��2֡(�м�/��β֡)����ֽڳ���
//const int DEV_FRAME2_FIXLEN			= 4;	//�м�֡�̶���Ϣ�ֽڳ���
//
///// ����֡���϶�ȡ������Ϣ(���߲���ͬʱ����)
//const int DEV_MIX_DATAMAXNUM		= 126;	//֡������ݸ���
//const int DEV_MIX_DATABESTNUM		= 46;	//֡������ݸ���(��֤����ʱ����Լ330ms����)
//// ������Ҫ���������ȼ�����,�ɸ�����Ҫ�޸�.
//const int DEV_MIXSEND_FIXLEN		= 11;	//֡�̶���Ϣ�ֽڳ���
//const int DEV_MIXSEND_ONEDATALEN	= 11;	//֡ÿ����(�����ݿ�)��Ϣ�ֽڳ���	
//const int DEV_MIXREC_FIXLEN			= 13;	//֡�̶���Ϣ�ֽڳ���
//const int DEV_MIXREC_ONEDATALEN		= 5;	//֡ÿ������Ϣ�ֽڳ���
//const int DEV_MIXREC_ONEBLOCKLEN	= 0;	//֡ÿ��������Ϣ�ֽڳ���(��Ͽ�ʹ��)
//
//const int DEV_MIXPARA_MAXNUM		= DEV_MIX_DATAMAXNUM;	//��϶�ȡ����������
//const int DEV_MIXPARA_BESTNUM		= DEV_MIX_DATAMAXNUM;	//��϶�ȡ��Ѳ�������
//
//const int DEV_BLOCK_MAXDATALEN				= 250;
//const int DEV_BLOCK_MINDATALEN				= 30;
/////����֡Ϊ�̶����ȣ�����֡�к�������Ϣ
//const int DEV_BLOCK_MAXLEN                  = 255;  //����֡����󳤶�(�ֽ�)
//const int DEV_BLOCK_DATAMAXNUM				= 120;   //֡Я����������ݸ���(�̵����ͼĴ�����һ��������ϸ��ʱ�ٸģ������Զ�2008���̵����������Զ�125���Ĵ���)
//const int DEV_BLOCK_DATABESTNUM				= 115;   //֡������ݸ���(��֤����ʱ����Լ300ms���ң����Զ�230��8��1840���̵��������Զ�230/2 = 115���Ĵ���)
//
//const int DEV_BLOCKSEND_FIXLEN				= 8;    //����֡�й̶���Ϣ�ֽڳ���
//
//const int DEV_BLOCKREC_FIXLEN				= 5;    //����֡�й̶���Ϣ�ֽڳ���
//const int DEV_BLOCKREC_ONEDATALEN			= 2;   //����֡��ÿ��������Ϣ�ֽڳ���(�̵����ͼĴ�����һ��������ϸ��ʱ�ٸģ��Ȱ��Ĵ�������)
//
//const int DEV_BLOCK_BESTSPACE			    = 8;     //��ȡ��Ѽ��
///////////////////////////////////////////////////////////////////////////////
//
////������ȡ��д���豸����������ݸ���
////const int DEV_READP_MAXNUM					= 112;
////const int DEV_WRITEP_MAXNUM					= 270;//û�ã���д���õ�260
//const int DEV_BLOCK_MAXNUM						= 250;
////���Ĵ���������ȡ�����鳤:
//const int DEV_READBLK_MAXNUM[]		= 
//{ 	
//	{120},//1��
//	{120},//0��
//	{120},//3��
//	{120},//4��
//};
////���Ĵ�������д������鳤:
//const int DEV_WRITEBLK_MAXNUM[]		= 
//{ 
//	{0},//1��ֻ��
//	{120},//0��
//	{0},//3��ֻ��
//	{120},//4��
//};
//
///// MCGS���豸����忪ʼ ///////////////////////////////
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
//const CString	DEV_STR_READMUTIREG		= _T("ReadMutiReg");  //������Ĵ���(�������������)
//const CString	DEV_STR_WRITEMUTIREG	= _T("WriteMutiReg"); //д����Ĵ���(�������������)
////ͨ��д��,����ʵ��
//const CString	DEV_STR_MCGSWRITE		= _T("MCGS_WRITE");
//
//const CString	DEV_STR_SETHIDDENPRO	= _T("SetHiddenPro");
//const CString	DEV_STR_GETHIDDENPRO	= _T("GetHiddenPro");
//
//const DWORD DEV_DWORD_IOCTRLTYPENUM			= 12;
//const CString IOCTRL_STR_PROPERTYNAME[]		= 
//{
//	DEV_STR_READ,			//0.��ȡ
//	DEV_STR_WRITE,		//1.д��
//	DEV_STR_READ32,		//2.32λ���ݶ�ȡ���ַ���
//	DEV_STR_WRITE32,		//3.32λ����д��(����Ϊ�ַ���)
//	DEV_STR_READP,		//4.������ȡ
//	DEV_STR_WRITEP,		//5.����д��
//	DEV_STR_READPV,		//6.������ȡ(�����Զ��ۼ�)
//	DEV_STR_WRITEPV,		//7.����д��(�����Զ��ۼ�)
//	DEV_STR_READBLOCK,	//8.������ȡ(�䷽��ʽ���)
//	DEV_STR_WRITEBLOCK,	//9.����д��(�䷽��ʽ��д)
//	DEV_STR_READMUTIREG,	//10.������Ĵ���
//	DEV_STR_WRITEMUTIREG,	//11.������Ĵ���
//};
//
//enum DEV_IOCTRL_TYPE		//�������涨��ͬ���޸ĸ���
//{
//	DEV_IOCTRL_READ			= 0,//0.��ȡ
//	DEV_IOCTRL_WRITE		= 1,//1.д��
//	DEV_IOCTRL_READ32		= 2,//2.32λ���ݶ�ȡ���ַ���
//	DEV_IOCTRL_WRITE32		= 3,//3.32λ����д��(����Ϊ�ַ���)
//	DEV_IOCTRL_READP		= 4,//4.������ȡ
//	DEV_IOCTRL_WRITEP		= 5,//5.����д��
//	DEV_IOCTRL_READPV		= 6,//6.������ȡ(�����Զ��ۼ�)
//	DEV_IOCTRL_WRITEPV		= 7,//7.����д��(�����Զ��ۼ�)
//	DEV_IOCTRL_READBLOCK	= 8,//8.������ȡ(�䷽��ʽ���)
//	DEV_IOCTRL_WRITEBLOCK	= 9,//9.����д��(�䷽��ʽ��д)
//	DEV_IOCTRL_READMUTIREG	=10,//10.������ȡ���ַ���
//	DEV_IOCTRL_WRITEMUTIREG	=11,//11.����д����ַ���
//};
//
//const int DEV_CMD_MAXNUM		= 512; //��ȡ��д���豸����������ݸ���(����)
//const int DEV_CMD_MAXADDRESS	= 65535; //��ȡ��д���豸��������ַ��Χ
///// MCGS���豸�������� ///////////////////////////////
//
/////�����汾��Ϣ,��3λ������3λС�����,��������:
////1.�������ֶ�Ӧ����Ĺ��ܻ������Եı���޸�
////2.С�����ֶ�Ӧ��BUG�޸Ļ�С����ԭ�������޹صı䶯
//#define DEV_DOUBLE_VER		   005.012	//�����汾��,С����ǰ��ʾ��ĸĶ���С������һλ��ʾ���ư汾���ڶ�λ��ʾ�Դ�ĸĶ������һλ��ʾС�Ķ�
//#define DEV_DOUBLE_VEREXT	   0		//��չ�汾��(Ŀǰδʹ��)


//PLC��ǩ����ͨ����������
typedef enum VarType
{
	PLC_BOOL,		//PLC��bool��������Ӧһ��bit;
	PLC_BYTE,		//PLC��bool��������Ӧһ��bit;
	PLC_CHAR,		//PLC��bool��������Ӧһ��bit;
	PLC_WCHAR,		//PLC��bool��������Ӧһ��bit;
	PLC_SINT,		//PLC��bool��������Ӧһ��bit;
	PLC_USINT,		//PLC��bool��������Ӧһ��bit;
	PCL_INT,		//PLC��bool��������Ӧһ��bit;
	PCL_UINT,		//PLC��bool��������Ӧһ��bit;
	PLC_DINT,		//PLC��bool��������Ӧһ��bit;
	PLC_UDINT,		//PLC��bool��������Ӧһ��bit;
	PLC_WORD,
	PLC_DWORD,
	PLC_LWORD, 

	PLC_REAL,		//PLC��bool��������Ӧһ��bit;
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

	//��;ϵͳ����
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