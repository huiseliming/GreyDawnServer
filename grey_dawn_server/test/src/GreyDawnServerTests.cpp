#include <gtest/gtest.h>
#include "TcpListener.h"
#include "Session.h"
#include "Log.h"


TEST(GreyDawnServerTests, GreyDawnServerTest)
{
	Initialize_spdlog();
	{
		asio::io_service service;
		TcpListener<SessionBase> TL(service, asio::ip::tcp::endpoint(asio::ip::address(),50122));
		std::thread thread(
			[&]
			{
				service.run();
			}
		);
		std::this_thread::sleep_for(std::chrono::seconds(1));
		TL.Stop();
		thread.join();
	}
	Shutdown_spdlog();
}
