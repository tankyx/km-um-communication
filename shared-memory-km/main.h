#pragma once
#include <ntdef.h>
#include <ntifs.h>
#include <ntddk.h>
#include <windef.h>
#include <Ntstrsafe.h>

#define InitialStack_1909		0x28
#define KernelStack_1909		0x58
#define VCreateTime_1909		0x600
#define StartAddress_1909		0x620
#define CID_1909				0x648
#define Win32StartAddress_1909	0x6a0
#define ExitStatus_1909			0x710



#define InitialStack_UP			0x28
#define KernelStack_UP			0x58
#define VCreateTime_UP			0x430
#define StartAddress_UP			0x450
#define CID_UP					0x478
#define Win32StartAddress_UP	0x4d0
#define ExitStatus_UP			0x548

#define ImageFileName_1909		0x450
#define ActiveThreads_1909		0x498
#define ActiveProcessLinks_1909	0x2F0

#define ImageFileName_UP		0x5a8
#define ActiveThreads_UP		0x5f0
#define ActiveProcessLinks_UP	0x448

ULONG GInitialStack;
ULONG GVCreateTime;
ULONG GStartAddress;
ULONG GWin32StartAddress;
ULONG GKernelStack;
ULONG GImageFileName;
ULONG GActiveThreads;
ULONG GActiveProcessLinks;
ULONG GExitStatus;
ULONG GCID;

PVOID _VCreateTime;
PVOID _StartAddress;
PVOID _Win32StartAddress;
PVOID _KernelStack;
PVOID _ExitStatus;
PVOID _CID;

const WCHAR SharedSectionName[] = L"\\BaseNamedObjects\\shared-memory";

PVOID	pSharedSection = NULL;
PVOID	pSectionObj = NULL;
HANDLE	hSection = NULL;

VOID DriverUnload(IN PDRIVER_OBJECT pDriverObject);
NTSTATUS CreateCall(PDEVICE_OBJECT DeviceObject, PIRP irp);
NTSTATUS CloseCall(PDEVICE_OBJECT DeviceObject, PIRP irp);

SECURITY_DESCRIPTOR SecDescriptor;
HANDLE sectionHandle;
PVOID	SharedSection = NULL;
PVOID	Sharedoutputvar = NULL;
ULONG DaclLength;
PACL Dacl;

HANDLE  SharedEventHandle_trigger = NULL;
PKEVENT SharedEvent_trigger = NULL;
UNICODE_STRING EventName_trigger;

HANDLE  SharedEventHandle_ReadyRead = NULL;
PKEVENT SharedEvent_ReadyRead = NULL;
UNICODE_STRING EventName_ReadyRead;

HANDLE  SharedEventHandle_dt = NULL;
PKEVENT SharedEvent_dt = NULL;
UNICODE_STRING EventName_dt;

extern NTKERNELAPI ERESOURCE PsLoadedModuleResource;
NTSTATUS ZwQuerySystemInformation(ULONG InfoClass, PVOID Buffer, ULONG Length, PULONG ReturnLength);
