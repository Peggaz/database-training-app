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

// TEST(DisplayDb, DisplayNonEmptyDb){
//      Student adam{
//         "Adad", 
//         "Smith", 
//         "ul dobra 123, 00-200 Warszawa",
//         123456,
//         "11223344567",
//         Gender::Male
//     };
//     Database db;
//     EXPECT_TRUE(db.add(adam)); 
//     db.display();
// }