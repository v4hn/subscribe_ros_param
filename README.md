# subscribe_ros_param

This is an attempt to hijack ROS' cached parameter updates for callbacks.

It should work, but in my experiments the parameter subscription always fails and `getCachedParam` effectively reverts to `getParam`.

That might be a problem in upstream ROS kinetic+.
Feel free to test and report back here!
