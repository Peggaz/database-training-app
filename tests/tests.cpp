#include <gtest/gtest.h>
#include "..\src\database.hpp"
#include "..\src\student.hpp"
#include <string>
struct DatabaseTest : ::testing::Test
{
    Database db;
};

TEST_F(DatabaseTest, CanAddStudentToDb) {
    Student adam{
        "Adad", 
        "Smith", 
        "ul dobra 123, 00-200 Warszawa",
        123456,
        "11223344567",
        Gender::Male
    };

    EXPECT_TRUE(db.add(adam));   
    EXPECT_FALSE(db.add(adam));
}

TEST_F(DatabaseTest, DisplayEmptyDb){
    std::string content = db.show();
    std::string expectedContent = "";
    EXPECT_EQ(content, expectedContent);
}

TEST_F(DatabaseTest, DisplayNonEmptyDb){
     Student adam{
        "Adad", 
        "Smith", 
        "ul awd 123, 00-200 Poznań",
        123456,
        "11223344567",
        Gender::Male
    };
    EXPECT_TRUE(db.add(adam)); 

    std::string content = db.show();
    std::string expectedContent = "Adad Smith; ul awd 123, 00-200 Poznań; 123456; 11223344567; Male\n";
    EXPECT_EQ(content, expectedContent);
}