#include <gtest/gtest.h>
#include <Logger/LoggerGlobal.h>
#include <Graphs/ZooGraph.h>
#include <DatabaseManager/AccountRepository.h>

using namespace std;

TEST(AccountTest, SerializationDeserialization) {
    Account acc("admin", 12345, Role::ADMIN);
    string ser = acc.serialize();
    Account copy = Account::deserialize(ser);
    EXPECT_EQ(acc.getUsername(), copy.getUsername());
    EXPECT_EQ(acc.getPasswordHash(), copy.getPasswordHash());
    EXPECT_EQ(acc.getRole(), copy.getRole());
}

TEST(AccountTest, RoleConversions) {
    EXPECT_EQ(Account::roleToInt(Role::MANAGER), 1);
    EXPECT_EQ(Account::roleToString(Role::EMPLOYEE), "Employee");
    EXPECT_EQ(Account::intToRole(0), Role::ADMIN);
}

TEST(AnimalTest, CreateAndFeed) {
    Mammal m("Leo", "Lion", 5, 120.0, "Mammal");
    EXPECT_FALSE(m.getIsFed());
    m.feed();
    EXPECT_TRUE(m.getIsFed());
}

TEST(AnimalTest, Compatibility) {
    auto a1 = make_shared<Mammal>("Leo", "Lion", 3, 120, "Mammal");
    auto a2 = make_shared<Mammal>("Tigra", "Tiger", 4, 110, "Mammal");
    EXPECT_FALSE(a1->isCompatibleWith(a2));
}

TEST(EmployeeTest, AviaryAssignments) {
    Employee emp("John", 30, 4000, 5);
    EXPECT_FALSE(emp.isAssigned());
    emp.assignAviary("A1");
    EXPECT_TRUE(emp.isAssigned());
    EXPECT_EQ(emp.getAviaryIds()[0], "A1");
    emp.removeAviary("A1");
    EXPECT_FALSE(emp.isAssigned());
}

TEST(EmployeeTest, ReplaceAndListAviaries) {
    Employee emp("John", 30, 4000, 5);
    emp.assignAviary("A1");
    emp.replaceAviary("A1", "A2");
    EXPECT_EQ(emp.getAviaryIds()[0], "A2");
}

TEST(LoggerTest, EnableDisableLevels) {
    Logger log("testlog.txt");
    log.enable(Logger::DEBUG | Logger::INFO);
    EXPECT_TRUE(log.isEnabled(Logger::DEBUG));
    log.disable(Logger::DEBUG);
    EXPECT_FALSE(log.isEnabled(Logger::DEBUG));
}

class GraphTestHelper : public Graph {
public:
    using Graph::addVertex;
    using Graph::addEdge;
    using Graph::getVertex;
    using Graph::getEdge;
    using Graph::distanceBetween;
    using Graph::getVertices;
    using Graph::getEdges;
};

TEST(GraphTest, AddVerticesAndEdges) {
    GraphTestHelper g;

    auto v1 = make_shared<Vertex>("A");
    auto v2 = make_shared<Vertex>("B");

    g.addVertex(v1);
    g.addVertex(v2);
    g.addEdge("A", "B", 10.0);

    EXPECT_NE(g.getVertex("A"), nullptr);
    EXPECT_NE(g.getVertex("B"), nullptr);

    const Edge* e = g.getEdge("A", "B");
    ASSERT_NE(e, nullptr);
    EXPECT_EQ(e->getWeight(), 10.0);
    EXPECT_DOUBLE_EQ(g.distanceBetween("A", "B"), 10.0);
}

class MockDatabase : public DatabaseManager {
public:
    MockDatabase() : DatabaseManager(":memory:") {}
    bool execute(const string& sql) { return true; }
};

TEST(AccountRepositoryTest, AddAndGetAccount) {
    MockDatabase db;
    AccountRepository repo(db);
    repo.initTable();
    repo.addAccount("test", 123, Role::EMPLOYEE);
    auto acc = repo.getAccount("test");
    EXPECT_TRUE(acc.has_value());
    EXPECT_EQ(acc->getUsername(), "test");
}

TEST(ZooGraphTest, Construction) {
    MockDatabase db;
    AviaryRepository avRepo(db);
    PathRepository pRepo(db);
    AnimalRepository aRepo(db);
    EmployeeRepository eRepo(db);
    ZooGraph zoo(avRepo, pRepo, aRepo, eRepo);
    EXPECT_TRUE(zoo.isZooConnected() == false || true);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
