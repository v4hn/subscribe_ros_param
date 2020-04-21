#include <ros/ros.h>
#include <ros/xmlrpc_manager.h>

const std::string PARAMETER {"test_parameter"};

namespace ros {
std::set<std::string> g_subscribed_params;
namespace param {
void paramUpdateCallback(XmlRpc::XmlRpcValue& params, XmlRpc::XmlRpcValue& result);
}
}


void paramUpdate(XmlRpc::XmlRpcValue& params, XmlRpc::XmlRpcValue& result){
	ROS_INFO_STREAM("paramUpdate called: " << static_cast<std::string>(params[1]));
	if(static_cast<std::string>(params[1]) == PARAMETER)
		ROS_INFO_STREAM(PARAMETER << ": updated to new value " << static_cast<std::string>(params[2]));

	ros::param::paramUpdateCallback(params, result);
}

int main(int argc, char** argv){
	ros::init(argc, argv, "parameter_subscriber");
	ros::NodeHandle nh{};

	std::string param{};

	nh.getParamCached(PARAMETER, param);
	ros::XMLRPCManager::instance()->bind("paramUpdate", paramUpdate);

	ros::Rate r(1);
	while(ros::ok()){
		ROS_INFO_STREAM(PARAMETER << ": '" << param << "' / subscribed_params: " << ros::g_subscribed_params.size());
		nh.getParamCached(PARAMETER, param);
		ros::spinOnce();
		r.sleep();
	}

	return 0;
}
