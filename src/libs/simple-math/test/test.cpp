#include <gtest/gtest.h>
#include <nlohmann/json.hpp>
#include <iostream>
#include <fstream>

#include <simple-math/add.h>


TEST (SimpleAdd, 2DVector){
    // parse my-info.json
    std::ifstream file(VIRTUAL_HUMANS_MY_INFO);
    auto json = nlohmann::json::parse(file);
    file.close();
    std::cout << "full name : " << json["full name"] << std::endl;
    std::cout << "student id: " << json["student id"] << std::endl;
    std::cout << "nethz name: " << json["nethz name"] << std::endl;

    EXPECT_TRUE((math::add({2,3}, {1,2}) == Eigen::Vector2f{3,5}));
}