#include <gtest/gtest.h>
#include "..\src\database.hpp"
#include "..\src\student.hpp"
#include <string>
struct DatabaseTest : ::testing::Test
{
    Database db;
    bool addAdam()
    {
        Student adam{
            "Adad", 
            "Smith", 
            "ul awd 123, 00-200 Poznan",
            123456,
            "11223344567",
            Gender::Male
        };
        return db.add(adam);
    }
};


TEST_F(DatabaseTest, CanAddStudentToDb) {
    EXPECT_TRUE(addAdam());   
    EXPECT_FALSE(addAdam());
}

TEST_F(DatabaseTest, DisplayEmptyDb){
    std::string content = db.show();
    std::string expectedContent = "";
    EXPECT_EQ(content, expectedContent);
}

TEST_F(DatabaseTest, DisplayNonEmptyDb){

    EXPECT_TRUE(addAdam()); 
    std::string content = db.show();
    std::string expectedContent = "Adad Smith; ul awd 123, 00-200 Poznan; 123456; 11223344567; Mezczyzna\n";
    EXPECT_EQ(content, expectedContent);
}

TEST_F(DatabaseTest, FaindPerPesel){
    addAdam();
    Student ada{
        "ada", 
        "Kowalski", 
        "ul awd 123, 00-200 Poznan",
        123456,
        "12223344567",
        Gender::Female
    };

    db.add(ada);
    Student* student = db.findPerPesel("12223344567");
    EXPECT_EQ(ada.getLastName(), student->getLastName());
}

TEST_F(DatabaseTest, FaindPerLastName){
    addAdam();
    Student ada{
        "ada", 
        "Kowalski", 
        "ul awd 123, 00-200 Poznan",
        123456,
        "12223344567",
        Gender::Female
    };

    db.add(ada);
    Student* student = db.findPerLastName("Kowalski");
    EXPECT_EQ(ada.getPesel(), student->getPesel());
}

TEST_F(DatabaseTest, RemovePerIndex){
    addAdam();
    db.removePerIndex(123456);
    EXPECT_EQ(db.show(), "");
}

TEST_F(DatabaseTest, SortedByLastName){
    addAdam();
    Student ada{
        "ada", 
        "Kowalski", 
        "ul awd 123, 00-200 Poznan",
        123456,
        "12223344567",
        Gender::Female
    };

    db.add(ada);
    db.sortedByLastName();
    EXPECT_EQ(db.show(), "ada Kowalski; ul awd 123, 00-200 Poznan; 123456; 12223344567; Kobieta\nAdad Smith; ul awd 123, 00-200 Poznan; 123456; 11223344567; Mezczyzna\n");
}

TEST_F(DatabaseTest, SortedByPesel){
    addAdam();
    Student ada{
        "ada", 
        "Kowalski", 
        "ul awd 123, 00-200 Poznan",
        123456,
        "12223344567",
        Gender::Female
    };

    db.add(ada);
    db.sortedByPesel();
    EXPECT_EQ(db.show(), "Adad Smith; ul awd 123, 00-200 Poznan; 123456; 11223344567; Mezczyzna\nada Kowalski; ul awd 123, 00-200 Poznan; 123456; 12223344567; Kobieta\n");
}
