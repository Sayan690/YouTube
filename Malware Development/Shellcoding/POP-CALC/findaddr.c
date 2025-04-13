#include <stdio.h>
#include <windows.h>

int main()
{
	HMODULE kernel32Addr;
	FARPROC funcAddr;

	kernel32Addr = GetModuleHandle("kernel32.dll");
	funcAddr = GetProcAddress(kernel32Addr, "WinExec");

	printf("Kernel32 address: 0x%p\n", kernel32Addr);
	printf("WinExec address: 0x%p\n", funcAddr);
}