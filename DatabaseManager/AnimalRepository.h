/**
* @file AnimalRepository.h
 * @author Denys Freyuk
 * @date 27.10.2025
 * @version 1.0
 * @brief Header defining AnimalRepository interfaces.
 */

#ifndef ANIMALREPOSITORY_H
#define ANIMALREPOSITORY_H
#include "DatabaseManager.h"
#include <unordered_map>
#include <memory>

using namespace std;

class AnimalManager;
class Animal;

/**
 * @class AnimalRepository
 * @brief Represents the AnimalRepository entity used in the Zoo Management System.
 * @details This class is part of the Zoo Management System database layer.
 */
/**
 * @example
 * AnimalRepository obj; // Example of using AnimalRepository methods.
 */

class AnimalRepository {

private:
    DatabaseManager& db;

public:
    AnimalRepository(DatabaseManager& database) : db(database) {}
    /**
     * @brief Method initTable.
     */
    void initTable();

    /**
     * @brief Method addAnimal.
     * @param a Parameter.
     */
    void addAnimal(const Animal& a);
    /**
     * @brief Method removeAnimal.
     * @param id Parameter.
     * @return Result value.
     */
    bool removeAnimal(const string& id);

    /**
     * @brief Method addAnimalInAviary.
     * @param aviaryId Parameter.
     * @param animalId Parameter.
     */
    void addAnimalInAviary(const string& aviaryId, const string& animalId);
    /**
     * @brief Method removeAnimalFromAviary.
     * @param aviaryId Parameter.
     * @param animalId Parameter.
     */
    void removeAnimalFromAviary(const string& aviaryId, const string& animalId);
    /**
     * @brief Method moveAnimal.
     * @param id Parameter.
     * @param oldAviaryId Parameter.
     * @param newAviaryId Parameter.
     * @return Result value.
     */
    bool moveAnimal(const string& id, const string& oldAviaryId, const string& newAviaryId);

    /**
     * @brief Method getAllAnimals.
     * @return Result value.
     */
    unordered_map<string, shared_ptr<Animal>> getAllAnimals();
    /**
     * @brief Method clearAll.
     */
    void clearAll();
};

#endif //ANIMALREPOSITORY_H
