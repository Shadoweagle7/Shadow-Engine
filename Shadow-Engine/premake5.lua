workspace "Shadow-Engine"
	architecture "x64"

	configurations {
		"Debug",
		"Release",
		"Distribution"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "Shadow-Engine/vendor/GLFW/include"

include "Shadow-Engine/vendor/GLFW"

project "Shadow-Engine"
	location "Shadow-Engine"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "se-pch.h"
	pchsource "Shadow-Engine/src/se-pch.cpp"

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs {
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}"
	}

	links {
		"GLFW",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17" 
		staticruntime "On"
		systemversion "latest"
		defines {
			"SE_PLATFORM_WINDOWS",
			"SE_BUILD_DLL"
		}

		postbuildcommands {
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "SE_DEBUG"
		symbols "On"
	filter "configurations:Release"
		defines "SE_RELEASE"
		optimize "On"
	filter "configurations:Distribution"
		defines "SE_DISTRIBUTION"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs {
		"Shadow-Engine/vendor/spdlog/include",
		"Shadow-Engine/src"
	}

	links {
		"Shadow-Engine"
	}

	filter "system:windows"
		cppdialect "C++17" 
		staticruntime "On"
		systemversion "latest"
		defines {
			"SE_PLATFORM_WINDOWS",
		}

	filter "configurations:Debug"
		defines "SE_DEBUG"
		symbols "On"
	filter "configurations:Release"
		defines "SE_RELEASE"
		optimize "On"
	filter "configurations:Distribution"
		defines "SE_DISTRIBUTION"
		optimize "On"