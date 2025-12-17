/*
Lifecycle

	1. Hardware/virtual device appears and matches your INF.
	2. PnP Manager loads your driver (calls DriverEntry).
	3. KMDF is set up by WdfDriverCreate and registers your callbacks.
	4. PnP announces a specific device instance --> KMDF calls KmdfHelloWorldEvtDeviceAdd.
	5. Inside EvtDeviceAdd, you create WDFDEVICE, configure I/O type, create I/O queues (WDFQUEUE), and register request handlers (e.g., EvtIoRead, EvtIoWrite, EvtIoDeviceControl).
*/

#include <ntddk.h>
#include <wdf.h>

DRIVER_INITIALIZE DriverEntry;
EVT_WDF_DRIVER_DEVICE_ADD KmdfHelloWorldEvtDeviceAdd;

NTSTATUS
DriverEntry(
	_In_ PDRIVER_OBJECT DriverObject,
	_In_ PUNICODE_STRING RegistryPath
) {
	NTSTATUS status = STATUS_SUCCESS;

	WDF_DRIVER_CONFIG config;

	KdPrintEx((DPFLTR_IHVDRIVER_ID, DPFLTR_INFO_LEVEL, "KmdfHelloWorld: DriverEntry\n"));

	WDF_DRIVER_CONFIG_INIT(&config, KmdfHelloWorldEvtDeviceAdd);

	status = WdfDriverCreate(DriverObject, RegistryPath, WDF_NO_OBJECT_ATTRIBUTES, &config, WDF_NO_HANDLE);

	return status;
}

NTSTATUS
KmdfHelloWorldEvtDeviceAdd(
	_In_ WDFDRIVER Driver,
	_Inout_ PWDFDEVICE_INIT DeviceInit
) {
	UNREFERENCED_PARAMETER(Driver);

	NTSTATUS status;

	WDFDEVICE hDevice;

	KdPrintEx((DPFLTR_IHVDRIVER_ID, DPFLTR_INFO_LEVEL, "KmdfHelloWorld: KmdfHelloWorldEvtDeviceAdd\n"));

	status = WdfDeviceCreate(&DeviceInit, WDF_NO_OBJECT_ATTRIBUTES, &hDevice);

	return status;
}
