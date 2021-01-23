#pragma once

//std
#include <algorithm>
#include <array>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>
#include <future>
#include <chrono>

//boost
#include <boost/date_time/gregorian/gregorian.hpp> //include all types plus i/o

//boost smartptr
#include<boost/smart_ptr/shared_ptr.hpp>
#include<boost/smart_ptr/weak_ptr.hpp>

//boost archive
#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>

//boost/Serialization
#include <boost/date_time/gregorian/greg_serialize.hpp>
#include <boost/serialization/shared_ptr.hpp>
#include <boost/serialization/weak_ptr.hpp>
#include <boost/serialization/vector.hpp>
