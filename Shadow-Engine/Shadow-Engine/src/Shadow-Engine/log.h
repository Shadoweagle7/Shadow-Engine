#ifndef SE_LOG
#define SE_LOG

#include "core.h"
#include "spdlog\spdlog.h"

#include <memory>

namespace shadow_engine {
	class SE_API log {
	private:
		static std::shared_ptr<spdlog::logger> core_logger;
		static std::shared_ptr<spdlog::logger> client_logger;
	public:
		static void init();

		inline static std::shared_ptr<spdlog::logger> &get_core_logger() { return core_logger; }
		inline static std::shared_ptr<spdlog::logger> &get_client_logger() { return client_logger; }
	};
}

// Logging macros

#ifdef _DEBUG
#define SE_DEBUG _DEBUG
#endif // _DEBUG

#ifdef SE_DEBUG

#define SE_CORE_TRACE(...)      ::shadow_engine::log::get_core_logger()->trace(__VA_ARGS__)
#define SE_CORE_WARN(...)       ::shadow_engine::log::get_core_logger()->warn(__VA_ARGS__)
#define SE_CORE_ERROR(...)      ::shadow_engine::log::get_core_logger()->error(__VA_ARGS__)
#define SE_CORE_CRITICAL(...)   ::shadow_engine::log::get_core_logger()->critical(__VA_ARGS__)
#define SE_CORE_DEBUG(...)      ::shadow_engine::log::get_core_logger()->debug(__VA_ARGS__)
#define SE_CORE_INFO(...)       ::shadow_engine::log::get_core_logger()->info(__VA_ARGS__)

#define SE_TRACE(...)           ::shadow_engine::log::get_client_logger()->trace(__VA_ARGS__)
#define SE_WARN(...)            ::shadow_engine::log::get_client_logger()->warn(__VA_ARGS__)
#define SE_ERROR(...)           ::shadow_engine::log::get_client_logger()->error(__VA_ARGS__)
#define SE_CRITICAL(...)        ::shadow_engine::log::get_client_logger()->critical(__VA_ARGS__)
#define SE_DEBUG(...)           ::shadow_engine::log::get_client_logger()->debug(__VA_ARGS__)
#define SE_INFO(...)            ::shadow_engine::log::get_client_logger()->info(__VA_ARGS__)

#else

// Don't compile debug and logging stuff in release mode

#define SE_CORE_TRACE(...)   
#define SE_CORE_WARN(...)    
#define SE_CORE_ERROR(...)   
#define SE_CORE_CRITICAL(...)
#define SE_CORE_DEBUG(...)   
#define SE_CORE_INFO(...)    

#define SE_TRACE(...)        
#define SE_WARN(...)         
#define SE_ERROR(...)        
#define SE_CRITICAL(...)     
#define SE_DEBUG(...)        
#define SE_INFO(...)         

#endif // SE_DEBUG

#endif // !SE_LOG


