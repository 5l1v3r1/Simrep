#pragma once

#ifndef CXX_KERNELUSERMANAGE_H
#define CXX_KERNELUSERMANAGE_H

#ifdef __cplusplus
extern "C" {
#endif

#include <ntifs.h>
#include <ntddk.h>
//#include <Ntstrsafe.h>

typedef struct _KERNELUSER
{
        LIST_ENTRY      ListEntry ;
        ULONG            UID ;
        UNICODE_STRING ustrUserName ;
}KERNELUSER, *PKERNELUSER ;

// ��ʼ���û�������
BOOLEAN InitializeKernelUserManage(void) ;

// �ͷ��û�������
BOOLEAN ReleaseKernelUserManage(void) ;

// ��ȡ�û����Լ���Ӧ��SID���û���������
BOOLEAN ReadKernelUser(void) ;

// ͨ��SID���һ���ж��û��Ƿ����
BOOLEAN UserIsExist(__in ULONG uUID) ;

// ͨ��SIDȡ���û���
PUNICODE_STRING GetUserNameByUID(__in ULONG uUID) ;

// ȡ�ý��������û�SID
BOOLEAN GetProcessSID(__in ULONG uPID, __inout PUNICODE_STRING pustrProcessSID) ;

// ȡ�ý����������û�id
ULONG GetProcessUID(__in ULONG uPID) ;

// ȡ�õ�ǰ���������û���
PUNICODE_STRING GetCurrentProcessUserName(VOID) ;

#ifdef ALLOC_PRAGMA
// Allow the DriverEntry routine to be discarded once initialization is completed
#pragma alloc_text(INIT, InitializeKernelUserManage)
#pragma alloc_text(PAGE, ReleaseKernelUserManage)
#pragma alloc_text(INIT, ReadKernelUser)
#pragma alloc_text(PAGE, UserIsExist)
#pragma alloc_text(PAGE, GetUserNameByUID)
#pragma alloc_text(PAGE, GetProcessSID)
#pragma alloc_text(PAGE, GetProcessUID)
#endif // ALLOC_PRAGMA

#ifdef __cplusplus
}
#endif
#endif