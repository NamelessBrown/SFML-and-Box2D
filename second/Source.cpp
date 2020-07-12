#include "Engine.h"
#include <memory>

int main()
{
	auto eng = std::make_unique<Engine>();
	eng->Run();
}