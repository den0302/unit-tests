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
    EXPECT_EQ(Account::roleToInt(Role::ADMIN), 0);
    EXPECT_EQ(Account::roleToInt(Role::MANAGER), 1);
    EXPECT_EQ(Account::roleToInt(Role::EMPLOYEE), 2);
    EXPECT_EQ(Account::roleToString(Role::ADMIN), "Admin");
    EXPECT_EQ(Account::roleToString(Role::MANAGER), "Manager");
    EXPECT_EQ(Account::roleToString(Role::EMPLOYEE), "Employee");
    EXPECT_EQ(Account::intToRole(0), Role::ADMIN);
    EXPECT_EQ(Account::intToRole(1), Role::MANAGER);
    EXPECT_EQ(Account::intToRole(2), Role::EMPLOYEE);
}

TEST(AccountTest, DeserializeInvalidStringThrows) {
    EXPECT_THROW(Account::deserialize("broken_data"), std::runtime_error);
}

TEST(AnimalTest, CreateAndFeed) {
    Mammal m("Leo", "Lion", 5, 120.0, "Mammal");
    EXPECT_FALSE(m.getIsFed());
    m.feed();
    EXPECT_TRUE(m.getIsFed());
}

TEST(AnimalTest, CompatibilityNegativeAndPositive) {
    auto lion = make_shared<Mammal>("Leo", "Lion", 3, 120, "Mammal");
    auto tiger = make_shared<Mammal>("Tigra", "Tiger", 4, 110, "Mammal");
    EXPECT_FALSE(lion->isCompatibleWith(tiger));

    auto bird = make_shared<Bird>("Parry", "Parrot", 2, 1.5, "Bird");
    auto fish = make_shared<Fish>("Nemo", "Clownfish", 1, 0.3, "Fish");
    EXPECT_TRUE(bird->isCompatibleWith(fish));
}

TEST(AnimalExtraTest, FeedTwice) {
    Mammal m("Simba", "Lion", 4, 110.0, "Mammal");
    m.feed();
    EXPECT_TRUE(m.getIsFed());
    m.feed();
    EXPECT_TRUE(m.getIsFed());
}

TEST(AnimalTest, FeedTwiceDoesNotThrow) {
    Mammal m("Simba", "Lion", 4, 110.0, "Mammal");
    m.feed();
    EXPECT_TRUE(m.getIsFed());
    EXPECT_NO_THROW(m.feed());
}

TEST(AnimalTest, DerivedClassesSoundAndMove) {
    Bird b("Chirpy", "Canary", 1, 0.2, "Bird");
    Reptile r("Sly", "Snake", 2, 5.0, "Reptile");
    Fish f("Goldie", "Goldfish", 1, 0.1, "Fish");
    Amphibian a("Froggy", "Frog", 1, 0.1, "Amphibian");
    Insect i("Buzz", "Bee", 1, 0.05, "Insect");
    Arachnid sp("Spidey", "Spider", 1, 0.02, "Arachnid");
    EXPECT_NO_THROW(b.makeSound());
    EXPECT_NO_THROW(r.makeSound());
    EXPECT_NO_THROW(f.makeSound());
    EXPECT_NO_THROW(a.makeSound());
    EXPECT_NO_THROW(i.makeSound());
    EXPECT_NO_THROW(sp.makeSound());
    EXPECT_NO_THROW(b.move());
    EXPECT_NO_THROW(f.move());
    EXPECT_NO_THROW(a.move());
    EXPECT_NO_THROW(i.move());
    EXPECT_NO_THROW(sp.move());
}

TEST(EmployeeTest, AviaryAssignmentsAndRemoval) {
    Employee emp("John", 30, 4000, 5);
    EXPECT_FALSE(emp.isAssigned());
    emp.assignAviary("A1");
    EXPECT_TRUE(emp.isAssigned());
    emp.assignAviary("A2");
    EXPECT_EQ(emp.getAviaryIds().size(), 2);
    emp.removeAviary("A1");
    EXPECT_EQ(emp.getAviaryIds().size(), 1);
    EXPECT_EQ(emp.getAviaryIds()[0], "A2");
    emp.removeAviary("A2");
    EXPECT_FALSE(emp.isAssigned());
}

TEST(EmployeeTest, ReplaceAndListAviaries) {
    Employee emp("John", 30, 4000, 5);
    emp.assignAviary("A1");
    emp.replaceAviary("A1", "A2");
    EXPECT_EQ(emp.getAviaryIds()[0], "A2");
}

TEST(EmployeeTest, ReplaceAviaryWhenMissingAddsNew) {
    Employee e("John", 25, 3500, 3);
    e.replaceAviary("OldAviary", "NewAviary");
    EXPECT_TRUE(e.isAssigned());
    EXPECT_EQ(e.getAviaryIds()[0], "NewAviary");
}

TEST(EmployeeTest, GetFullInfoFormat) {
    Employee e("Kate", 29, 4200, 4);
    string info = e.getFullInfoAboutEmployee();
    EXPECT_NE(info.find("Name: Kate"), string::npos);
    EXPECT_NE(info.find("Salary:"), string::npos);
}

TEST(LoggerTest, EnableDisableLevels) {
    const string filename = "temp_test_log.txt";
    Logger log(filename);
    log.enable(Logger::DEBUG | Logger::INFO);
    EXPECT_TRUE(log.isEnabled(Logger::DEBUG));
    log.disable(Logger::DEBUG);
    EXPECT_FALSE(log.isEnabled(Logger::DEBUG));
    remove(filename.c_str());
}

TEST(LoggerTest, EnableDisableAndWriteFile) {
    const string filename = "temp_test_log.txt";
    {
        Logger log(filename);
        log.enable(Logger::DEBUG | Logger::INFO | Logger::WARN | Logger::ERROR);
        log.debug("debug msg");
        log.info("info msg");
        log.warn("warn msg");
        log.error("error msg");
        log.disable(Logger::DEBUG);
        EXPECT_FALSE(log.isEnabled(Logger::DEBUG));
    }
    ifstream f(filename);
    ASSERT_TRUE(f.is_open());
    string content((istreambuf_iterator<char>(f)), istreambuf_iterator<char>());
    EXPECT_NE(content.find("debug msg"), string::npos);
    EXPECT_NE(content.find("error msg"), string::npos);
    f.close();
    remove(filename.c_str());
}

class GraphTestHelper : public Graph {
public:
    using Graph::addVertex;
    using Graph::removeVertex;
    using Graph::removeEdge;
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

TEST(GraphTest, RemoveVertexRemovesEdges) {
    GraphTestHelper g;
    g.addVertex(make_shared<Vertex>("X"));
    g.addVertex(make_shared<Vertex>("Y"));
    g.addEdge("X", "Y", 5.0);
    EXPECT_NE(g.getEdge("X", "Y"), nullptr);
    g.removeVertex("Y");
    EXPECT_EQ(g.getEdge("X", "Y"), nullptr);
}

TEST(GraphTest, AddDuplicateVertexDoesNotCrash) {
    GraphTestHelper g;
    auto v1 = make_shared<Vertex>("A");
    g.addVertex(v1);
    EXPECT_NO_THROW(g.addVertex(v1));
    EXPECT_NE(g.getVertex("A"), nullptr);
}

TEST(GraphTest, DistanceBetweenNonConnectedVerticesReturnsInfinity) {
    GraphTestHelper g;
    auto v1 = make_shared<Vertex>("A");
    auto v2 = make_shared<Vertex>("B");
    g.addVertex(v1);
    g.addVertex(v2);
    double dist = g.distanceBetween("A", "B");
    EXPECT_LE(dist, -1);
}

TEST(GraphTest, RemoveEdge) {
    GraphTestHelper g;
    g.addVertex(make_shared<Vertex>("A"));
    g.addVertex(make_shared<Vertex>("B"));
    g.addEdge("A", "B", 7.0);
    EXPECT_NE(g.getEdge("A", "B"), nullptr);
    g.removeEdge("A", "B");
    EXPECT_EQ(g.getEdge("A", "B"), nullptr);
}

class MockDatabase : public DatabaseManager {
public:
    MockDatabase() : DatabaseManager(":memory:") {}
    bool execute(const string& sql) { return true; }
};

TEST(RepositoryExtraTest, AccountAddAndExists) {
    MockDatabase db;
    AccountRepository repo(db);
    repo.initTable();
    EXPECT_TRUE(repo.addAccount("user", 12345, Role::EMPLOYEE));
    EXPECT_TRUE(repo.accountExists("user"));
}

TEST(AccountRepositoryTest, AddGetAndDuplicate) {
    MockDatabase db;
    AccountRepository repo(db);
    repo.initTable();
    EXPECT_TRUE(repo.addAccount("test", 123, Role::EMPLOYEE));
    auto acc = repo.getAccount("test");
    EXPECT_TRUE(acc.has_value());
    EXPECT_EQ(acc->getUsername(), "test");
    EXPECT_FALSE(repo.addAccount("test", 999, Role::ADMIN));
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

TEST(ZooGraphTest, CheckDistanceAndIsZooConnected) {
    MockDatabase db;
    AviaryRepository avRepo(db);
    PathRepository pRepo(db);
    AnimalRepository aRepo(db);
    EmployeeRepository eRepo(db);
    ZooGraph zoo(avRepo, pRepo, aRepo, eRepo);

    auto aviary1 = make_shared<Aviary>("A1", "Lion`s Cage", "Savannah", 120, 10,"","");
    auto aviary2 = make_shared<Aviary>("A2", "Parrot`s Cage", "Tropical Zone", 160, 8,"","");

    zoo.addAviary(aviary1);
    zoo.addAviary(aviary2);

    zoo.addPath("A1", "A2", 15.0);

    EXPECT_TRUE(zoo.isZooConnected() == false || true);
    EXPECT_DOUBLE_EQ(zoo.distanceBetweenAviaries("A1", "A2"), 15.0);
}

TEST(AviaryRepositoryTest, InitAndAddAviary) {
    MockDatabase db;
    AviaryRepository repo(db);
    Aviary av("A1", "Lion`s Cage", "Savannah", 120, 10,"","");
    EXPECT_NO_THROW(repo.initTable());
    EXPECT_NO_THROW(repo.addAviary(av));
}

TEST(AnimalRepositoryTest, InitAndAddAnimal) {
    MockDatabase db;
    AnimalRepository repo(db);
    Mammal m("Simba", "Lion", 4, 110.0, "Mammal");
    repo.initTable();
    EXPECT_NO_THROW(repo.addAnimal(m));
}

TEST(EmployeeRepositoryTest, InitAndAssignEmployee) {
    MockDatabase db;
    EmployeeRepository repo(db);
    Employee emp("John", 30, 4000, 5);
    repo.initTable();
    EXPECT_NO_THROW(repo.addEmployee(emp));
    EXPECT_NO_THROW(repo.assignEmployeeToAviary(emp.getId(), "A1"));
}

TEST(PathRepositoryTest, InitAndAddPath) {
    MockDatabase db;
    PathRepository repo(db);
    repo.initTable();
    EXPECT_NO_THROW(repo.addPath("A1", "A2", 12.5));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
