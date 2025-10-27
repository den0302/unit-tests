/**
 * @file ZooGraph.h
 * @author Denys Freyuk
 * @date 27.10.2025
 * @version 1.0
 * @brief Header for ZooGraph declarations.
 */

#ifndef ZOOGRAPH_H
#define ZOOGRAPH_H
#include <memory>
#include <string>
#include "Graph.h"
#include "../Creatures/EmployeeManager.h"
#include "../Creatures/AnimalManager.h"
#include "../DatabaseManager/AviaryRepository.h"
#include "../DatabaseManager/PathRepository.h"
#include "../DatabaseManager/AnimalRepository.h"
#include "../DatabaseManager/EmployeeRepository.h"
/**
 * @class Aviary
 * @brief Represents the Aviary entity in the zoo management system.
 * @details This class is part of the Zoo Management project.
 */
/**
 * @example
 * Aviary* obj = nullptr; // Create or obtain an instance
 * // Use the public interface as needed.
 */

class Aviary : public Vertex  {

private:
    string name;
    string type;
    double area;
    int capacity;
    vector<shared_ptr<Animal>> animals;
    string assignedEmployee;
    string animalsStrTemp;
public:
    Aviary(string& name,
           string& type,
           double area,
           int capacity);

    Aviary(string id,
                   string name,
                   string type,
                   double area,
                   int capacity,
                   string assignedEmployee,
                   const string animalsStr);

/**
 * @brief Method getAnimalsStrTemp.
 * @return Result value.
 */
    [[nodiscard]] const string& getAnimalsStrTemp() const;
/**
 * @brief Method clearAnimalsStrTemp.
 */
    void clearAnimalsStrTemp();
/**
 * @brief Method getAnimalsRef.
 * @return Result value.
 */
    vector<shared_ptr<Animal>>& getAnimalsRef();
/**
 * @brief Method getIdAviary.
 * @return Result value.
 */
    [[nodiscard]] string getIdAviary() const;
/**
 * @brief Method getName.
 * @return Result value.
 */
    [[nodiscard]] string getName() const;
/**
 * @brief Method getType.
 * @return Result value.
 */
    [[nodiscard]] string getType() const;
/**
 * @brief Method getArea.
 * @return Result value.
 */
    [[nodiscard]] double getArea() const;
/**
 * @brief Method getCapacity.
 * @return Result value.
 */
    [[nodiscard]] int getCapacity() const;
/**
 * @brief Method getAnimals.
 * @return Result value.
 */
    [[nodiscard]] const vector<shared_ptr<Animal>>& getAnimals() const;
/**
 * @brief Method getAnimalById.
 * @param id Parameter.
 * @return Result value.
 */
    [[nodiscard]] shared_ptr<Animal> getAnimalById(const string& id) const;
/**
 * @brief Method getAssignedEmployee.
 * @return Result value.
 */
    [[nodiscard]] string getAssignedEmployee() const;
/**
 * @brief Method getAnimalsStr.
 * @return Result value.
 */
    [[nodiscard]] string getAnimalsStr() const;

/**
 * @brief Method setName.
 * @param n Parameter.
 */
    void setName(const string& n);
/**
 * @brief Method setType.
 * @param t Parameter.
 */
    void setType(const string& t);
/**
 * @brief Method setArea.
 * @param a Parameter.
 */
    void setArea(double a);
/**
 * @brief Method setCapacity.
 * @param c Parameter.
 */
    void setCapacity(int c);
/**
 * @brief Method setAnimals.
 * @param an Parameter.
 */
    void setAnimals(vector<shared_ptr<Animal>> an);
/**
 * @brief Method setAssignedEmployee.
 * @param employeeId Parameter.
 */
    void setAssignedEmployee(const string& employeeId);
/**
 * @brief Method setAnimals.
 * @param animals Parameter.
 */
    void setAnimals(const string& animals);

/**
 * @brief Method printInfoAboutAviary.
 */
    void printInfoAboutAviary() const;

/**
 * @brief Method hasAnimal.
 * @param animalId Parameter.
 * @return Result value.
 */
    [[nodiscard]] bool hasAnimal(const string& animalId) const;
/**
 * @brief Method canAddAnimal.
 * @param animal Parameter.
 * @return Result value.
 */
    [[nodiscard]] bool canAddAnimal(const shared_ptr<Animal>& animal) const;

/**
 * @brief Method addAnimal.
 * @param animal Parameter.
 * @return Result value.
 */
    bool addAnimal(const shared_ptr<Animal>& animal) ;
/**
 * @brief Method removeAnimal.
 * @param id Parameter.
 * @return Result value.
 */
    bool removeAnimal(const string& id);
/**
 * @brief Method removeAssignedEmployee.
 */
    void removeAssignedEmployee();

/**
 * @brief Method listAnimals.
 */
    void listAnimals() const;
};

/**
 * @class Path
 * @brief Represents the Path entity in the zoo management system.
 * @details This class is part of the Zoo Management project.
 */
/**
 * @example
 * Path* obj = nullptr; // Create or obtain an instance
 * // Use the public interface as needed.
 */

class Path : public Edge  {

public:
    Path(const string& from, const string& to, double length)
        : Edge(from, to, length) {}
/**
 * @brief Method getFromId.
 * @return Result value.
 */
    [[nodiscard]] string getFromId() const;
/**
 * @brief Method getToId.
 * @return Result value.
 */
    [[nodiscard]] string getToId() const;
/**
 * @brief Method getLength.
 * @return Result value.
 */
    [[nodiscard]] double getLength() const;
};

/**
 * @class ZooGraph
 * @brief Represents the ZooGraph entity in the zoo management system.
 * @details This class is part of the Zoo Management project.
 */
/**
 * @example
 * ZooGraph* obj = nullptr; // Create or obtain an instance
 * // Use the public interface as needed.
 */

class ZooGraph : public Graph  {

private:
    AviaryRepository& repoAv;
    PathRepository& repoPth;
    AnimalRepository& animalRepo;
    EmployeeRepository& employeeRepo;

    AnimalManager animalManager;
    EmployeeManager employeeManager;
public:
/**
 * @brief Method ZooGraph.
 * @param aviaryRrepository Parameter.
 * @param pathRepository Parameter.
 * @param animalRepository Parameter.
 * @param employeeRepository Parameter.
 */
    ZooGraph(AviaryRepository& aviaryRrepository, PathRepository& pathRepository, AnimalRepository& animalRepository, EmployeeRepository& employeeRepository);

/**
 * @brief Method loadAviariesFromRepo.
 * @param repo Parameter.
 */
    void loadAviariesFromRepo(AviaryRepository& repo);
/**
 * @brief Method loadPathsFromRepo.
 * @param repo Parameter.
 */
    void loadPathsFromRepo(PathRepository& repo);

/**
 * @brief Method getAnimalManager.
 * @return Result value.
 */
    AnimalManager& getAnimalManager();
/**
 * @brief Method getEmployeeManager.
 * @return Result value.
 */
    EmployeeManager& getEmployeeManager();

/**
 * @brief Method getAviaries.
 * @return Result value.
 */
    const unordered_map<string, shared_ptr<Vertex>>& getAviaries() const;
/**
 * @brief Method getPaths.
 * @return Result value.
 */
    vector<Edge> getPaths() const;
/**
 * @brief Method getPath.
 * @param fromId Parameter.
 * @param toId Parameter.
 * @return Result value.
 */
    const Edge* getPath(const string& fromId, const string& toId) const;
/**
 * @brief Method getAviaryById.
 * @param id Parameter.
 * @return Result value.
 */
    shared_ptr<Vertex> getAviaryById(const string& id) const;
/**
 * @brief Method getAviaryNameById.
 * @param id Parameter.
 * @return Result value.
 */
    string getAviaryNameById(const string& id) const;
/**
 * @brief Method getNeighborsNames.
 * @param aviaryId Parameter.
 * @return Result value.
 */
    vector<string> getNeighborsNames(const string& aviaryId) const;
/**
 * @brief Method getNeighborsId.
 * @param aviaryId Parameter.
 * @return Result value.
 */
    vector<string> getNeighborsId(const string& aviaryId) const;

/**
 * @brief Method addAviary.
 * @param aviary Parameter.
 */
    void addAviary(shared_ptr<Aviary> aviary);
/**
 * @brief Method addPath.
 * @param fromId Parameter.
 * @param toId Parameter.
 * @param length Parameter.
 */
    void addPath(const string& fromId, const string& toId, double length);

/**
 * @brief Method removeAviary.
 * @param id Parameter.
 */
    void removeAviary(const string& id);
/**
 * @brief Method removePath.
 * @param fromId Parameter.
 * @param toId Parameter.
 */
    void removePath(const string& fromId, const string& toId);

/**
 * @brief Method findShortestPath.
 * @param startId Parameter.
 * @param endId Parameter.
 * @return Result value.
 */
    vector<string> findShortestPath(const string& startId, const string& endId) const;
/**
 * @brief Method distanceBetweenAviaries.
 * @param fromId Parameter.
 * @param toId Parameter.
 * @return Result value.
 */
    double distanceBetweenAviaries(const string& fromId, const string& toId) const;

/**
 * @brief Method isZooConnected.
 * @return Result value.
 */
    bool isZooConnected() const;

/**
 * @brief Method printPathBetweenAviaries.
 * @param fromId Parameter.
 * @param toId Parameter.
 */
    void printPathBetweenAviaries(const string& fromId, const string& toId) const;

/**
 * @brief Method listAnimals.
 */
    void listAnimals() const;
/**
 * @brief Method listEmployees.
 */
    void listEmployees() const;
/**
 * @brief Method printAviaries.
 */
    void printAviaries() const;
/**
 * @brief Method printZoo.
 */
    void printZoo() const;
};

#endif //ZOOGRAPH_H
