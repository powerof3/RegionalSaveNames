#include "Hooks.h"

namespace RegionalSaveNames
{
	struct DoNameSave
	{
		static void func(RE::BGSSaveLoadManager*, RE::BSSaveDataSystemUtility*, RE::BGSSaveLoadFileEntry*)
		{
			return;
		}
		static inline constexpr size_t size = OFFSET(0x4F1, 0x1DC);
	};

	void Install()
	{
		REL::Relocation<std::uintptr_t> target{ RELOCATION_ID(34874, 35785) };
		stl::asm_replace<DoNameSave>(target.address());
	}
}
