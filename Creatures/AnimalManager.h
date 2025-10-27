/**
 * @file AnimalManager.h
 * @author Denys Freyuk
 * @date 27.10.2025
 * @version 1.0
 * @brief Header for AnimalManager declarations.
 */

#ifndef ANIMALMANAGER_H
#define ANIMALMANAGER_H
#include "Animals.h"
#include "../DatabaseManager/AnimalRepository.h"
#include <unordered_map>
#include <vector>

class ZooGraph;

/**
 * @class AnimalManager
 * @brief Represents the AnimalManager entity in the zoo management system.
 * @details This class is part of the Zoo Management project.
 */
/**
 * @example
 * AnimalManager* obj = nullptr; // Create or obtain an instance
 * // Use the public interface as needed.
 */

class AnimalManager {

private:
    ZooGraph& zooGraph;
    AnimalRepository& animalRepo;
    unordered_map<string, shared_ptr<Animal>> animals;

public:
/**
 * @brief Method AnimalManager.
 * @param graph Parameter.
 * @param animalRepo Parameter.
 */
     AnimalManager(ZooGraph& graph, AnimalRepository& animalRepo);

    //void loadAnimalsFromRepo(AnimalRepository& animalRepo);
/**
 * @brief Method linkAnimalsToAviaries.
 */
    void linkAnimalsToAviaries();

/**
 * @brief Method getAnimals.
 * @return Result value.
 */
    const unordered_map<string, shared_ptr<Animal>>& getAnimals() const;

/**
 * @brief Method createAnimal.
 * @param name Parameter.
 * @param species Parameter.
 * @param age Parameter.
 * @param weight Parameter.
 * @param type Parameter.
 */
    void createAnimal(const string& name, const string& species, int age, double weight, const string& type);

/**
 * @brief Method addAnimalInAviary.
 * @param aviaryId Parameter.
 * @param animalId Parameter.
 * @return Result value.
 */
    bool addAnimalInAviary(const string& aviaryId, const string& animalId);
/**
 * @brief Method removeAnimalFromAviary.
 * @param aviaryId Parameter.
 * @param animalId Parameter.
 * @return Result value.
 */
    bool removeAnimalFromAviary(const string& aviaryId, const string& animalId);
/**
 * @brief Method removeAnimalFromAnimals.
 * @param animalId Parameter.
 * @return Result value.
 */
    bool removeAnimalFromAnimals(const string& animalId);
/**
 * @brief Method moveAnimalBetweenAviaries.
 * @param fromAviaryId Parameter.
 * @param toAviaryId Parameter.
 * @param animalId Parameter.
 * @return Result value.
 */
    bool moveAnimalBetweenAviaries(const string& fromAviaryId, const string& toAviaryId, const string& animalId);

/**
 * @brief Method getAnimalsNotInAviaries.
 * @return Result value.
 */
    vector<shared_ptr<Animal>> getAnimalsNotInAviaries() const;
/**
 * @brief Method allAnimalsAssigned.
 * @return Result value.
 */
    bool allAnimalsAssigned() const;

/**
 * @brief Method feedById.
 * @param animalId Parameter.
 */
    void feedById(const string& animalId);

/**
 * @brief Method listAllAnimals.
 */
    void listAllAnimals() const;
};


#endif //ANIMALMANAGER_H
