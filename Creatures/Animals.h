/**
 * @file Animals.h
 * @author Denys Freyuk
 * @date 27.10.2025
 * @version 1.0
 * @brief Header for Animals declarations.
 */

#ifndef ANIMALS_H
#define ANIMALS_H

#include <string>
#include <memory>
class ZooGraph;

using namespace std;

/**
 * @class Animal
 * @brief Represents the Animal entity in the zoo management system.
 * @details This class is part of the Zoo Management project.
 */
/**
 * @example
 * Animal* obj = nullptr; // Create or obtain an instance
 * // Use the public interface as needed.
 */

class Animal {

protected:
    string id;
    string name;
    string species;  // вид тварини(лев, тигр, папуга...)
    int age;
    double weight;
    string type;
    string aviaryId;
    bool isFed = false;

public:
/**
 * @brief Method Animal.
 * @param name Parameter.
 * @param species Parameter.
 * @param age Parameter.
 * @param weight Parameter.
 * @param type Parameter.
 */
    Animal(const string& name, const string& species, int age, double weight, const string& type);
/**
 * @brief Method Animal.
 * @param id Parameter.
 * @param name Parameter.
 * @param species Parameter.
 * @param age Parameter.
 * @param weight Parameter.
 * @param type Parameter.
 * @param aviaryId Parameter.
 */
    Animal(const string& id, string& name, string& species, int age, double weight, const string& type, string& aviaryId);
/**
 * @brief Destructor ~Animal.
 */
    virtual ~Animal() = default;

/**
 * @brief Method getId.
 * @return Result value.
 */
    [[nodiscard]] string getId() const;
/**
 * @brief Method getName.
 * @return Result value.
 */
    [[nodiscard]] string getName() const;
/**
 * @brief Method getSpecies.
 * @return Result value.
 */
    [[nodiscard]] string getSpecies() const;
/**
 * @brief Method getType.
 * @return Result value.
 */
    [[nodiscard]] string getType() const;
/**
 * @brief Method getAge.
 * @return Result value.
 */
    [[nodiscard]] int getAge() const;
/**
 * @brief Method getWeight.
 * @return Result value.
 */
    [[nodiscard]] double getWeight() const;
/**
 * @brief Method getIsFed.
 * @return Result value.
 */
    [[nodiscard]] bool getIsFed() const;
/**
 * @brief Method getAviaryId.
 * @return Result value.
 */
    [[nodiscard]] string getAviaryId() const;

/**
 * @brief Method setAviaryId.
 * @param id Parameter.
 */
    void setAviaryId(const string& id);
/**
 * @brief Method setName.
 * @param n Parameter.
 */
    void setName(const string& n);
/**
 * @brief Method setAge.
 * @param a Parameter.
 */
    void setAge(int a);
/**
 * @brief Method setWeight.
 * @param w Parameter.
 */
    void setWeight(double w);

/**
 * @brief Method feed.
 * @return Result value.
 */
    virtual void feed();
/**
 * @brief Method makeSound.
 * @return Result value.
 */
    virtual void makeSound() const = 0;
/**
 * @brief Method move.
 * @return Result value.
 */
    virtual void move() const;
/**
 * @brief Method isCompatibleWith.
 * @param other Parameter.
 * @return Result value.
 */
    [[nodiscard]] virtual bool isCompatibleWith(const shared_ptr<Animal>& other) const;

/**
 * @brief Method printInfoAboutAnimal.
 * @return Result value.
 */
    virtual void printInfoAboutAnimal() const;
};

/**
 * @class Mammal
 * @brief Represents the Mammal entity in the zoo management system.
 * @details This class is part of the Zoo Management project.
 */
/**
 * @example
 * Mammal* obj = nullptr; // Create or obtain an instance
 * // Use the public interface as needed.
 */

class Mammal : public Animal  {

public:
/**
 * @brief Method Mammal.
 * @param name Parameter.
 * @param species Parameter.
 * @param age Parameter.
 * @param weight Parameter.
 * @param type Parameter.
 */
    Mammal(const string& name, const string& species, int age, double weight, const string& type);
/**
 * @brief Method Mammal.
 * @param id Parameter.
 * @param name Parameter.
 * @param species Parameter.
 * @param age Parameter.
 * @param weight Parameter.
 * @param type Parameter.
 * @param aviaryId Parameter.
 */
    Mammal(const string& id, string& name, string& species, int age, double weight, const string& type, string& aviaryId);

/**
 * @brief Method makeSound.
 */
    void makeSound() const override;
};

/**
 * @class Bird
 * @brief Represents the Bird entity in the zoo management system.
 * @details This class is part of the Zoo Management project.
 */
/**
 * @example
 * Bird* obj = nullptr; // Create or obtain an instance
 * // Use the public interface as needed.
 */

class Bird : public Animal  {

public:
/**
 * @brief Method Bird.
 * @param name Parameter.
 * @param species Parameter.
 * @param age Parameter.
 * @param weight Parameter.
 * @param type Parameter.
 */
    Bird(const string& name, const string& species, int age, double weight, const string& type);

/**
 * @brief Method Bird.
 * @param id Parameter.
 * @param name Parameter.
 * @param species Parameter.
 * @param age Parameter.
 * @param weight Parameter.
 * @param type Parameter.
 * @param aviaryId Parameter.
 */
    Bird(const string& id, string& name, string& species, int age, double weight, const string& type, string& aviaryId);
/**
 * @brief Method makeSound.
 */
    void makeSound() const override;
/**
 * @brief Method move.
 */
    void move() const override;
};

/**
 * @class Reptile
 * @brief Represents the Reptile entity in the zoo management system.
 * @details This class is part of the Zoo Management project.
 */
/**
 * @example
 * Reptile* obj = nullptr; // Create or obtain an instance
 * // Use the public interface as needed.
 */

class Reptile : public Animal  {

public:
/**
 * @brief Method Reptile.
 * @param name Parameter.
 * @param species Parameter.
 * @param age Parameter.
 * @param weight Parameter.
 * @param type Parameter.
 */
    Reptile(const string& name, const string& species, int age, double weight, const string& type);
/**
 * @brief Method Reptile.
 * @param id Parameter.
 * @param name Parameter.
 * @param species Parameter.
 * @param age Parameter.
 * @param weight Parameter.
 * @param type Parameter.
 * @param aviaryId Parameter.
 */
    Reptile(const string& id, string& name, string& species, int age, double weight, const string& type, string& aviaryId);

/**
 * @brief Method makeSound.
 */
    void makeSound() const override;
};

/**
 * @class Fish
 * @brief Represents the Fish entity in the zoo management system.
 * @details This class is part of the Zoo Management project.
 */
/**
 * @example
 * Fish* obj = nullptr; // Create or obtain an instance
 * // Use the public interface as needed.
 */

class Fish : public Animal  {

public:
/**
 * @brief Method Fish.
 * @param name Parameter.
 * @param species Parameter.
 * @param age Parameter.
 * @param weight Parameter.
 * @param type Parameter.
 */
    Fish(const string& name, const string& species, int age, double weight, const string& type);
/**
 * @brief Method Fish.
 * @param id Parameter.
 * @param name Parameter.
 * @param species Parameter.
 * @param age Parameter.
 * @param weight Parameter.
 * @param type Parameter.
 * @param aviaryId Parameter.
 */
    Fish(const string& id, string& name, string& species, int age, double weight, const string& type, string& aviaryId);

/**
 * @brief Method makeSound.
 */
    void makeSound() const override;
/**
 * @brief Method move.
 */
    void move() const override;
};

/**
 * @class Amphibian
 * @brief Represents the Amphibian entity in the zoo management system.
 * @details This class is part of the Zoo Management project.
 */
/**
 * @example
 * Amphibian* obj = nullptr; // Create or obtain an instance
 * // Use the public interface as needed.
 */

class Amphibian : public Animal  {

public:
/**
 * @brief Method Amphibian.
 * @param name Parameter.
 * @param species Parameter.
 * @param age Parameter.
 * @param weight Parameter.
 * @param type Parameter.
 */
    Amphibian(const string& name, const string& species, int age, double weight, const string& type);
/**
 * @brief Method Amphibian.
 * @param id Parameter.
 * @param name Parameter.
 * @param species Parameter.
 * @param age Parameter.
 * @param weight Parameter.
 * @param type Parameter.
 * @param aviaryId Parameter.
 */
    Amphibian(const string& id, string& name, string& species, int age, double weight, const string& type, string& aviaryId);

/**
 * @brief Method makeSound.
 */
    void makeSound() const override;
/**
 * @brief Method move.
 */
    void move() const override;
};

/**
 * @class Insect
 * @brief Represents the Insect entity in the zoo management system.
 * @details This class is part of the Zoo Management project.
 */
/**
 * @example
 * Insect* obj = nullptr; // Create or obtain an instance
 * // Use the public interface as needed.
 */

class Insect : public Animal  {

public:
/**
 * @brief Method Insect.
 * @param name Parameter.
 * @param species Parameter.
 * @param age Parameter.
 * @param weight Parameter.
 * @param type Parameter.
 */
    Insect(const string& name, const string& species, int age, double weight, const string& type);
/**
 * @brief Method Insect.
 * @param id Parameter.
 * @param name Parameter.
 * @param species Parameter.
 * @param age Parameter.
 * @param weight Parameter.
 * @param type Parameter.
 * @param aviaryId Parameter.
 */
    Insect(const string& id, string& name, string& species, int age, double weight, const string& type, string& aviaryId);

/**
 * @brief Method makeSound.
 */
    void makeSound() const override;
/**
 * @brief Method move.
 */
    void move() const override;
};

/**
 * @class Arachnid
 * @brief Represents the Arachnid entity in the zoo management system.
 * @details This class is part of the Zoo Management project.
 */
/**
 * @example
 * Arachnid* obj = nullptr; // Create or obtain an instance
 * // Use the public interface as needed.
 */

class Arachnid : public Animal  {

public:
/**
 * @brief Method Arachnid.
 * @param name Parameter.
 * @param species Parameter.
 * @param age Parameter.
 * @param weight Parameter.
 * @param type Parameter.
 */
    Arachnid(const string& name, const string& species, int age, double weight, const string& type);
/**
 * @brief Method Arachnid.
 * @param id Parameter.
 * @param name Parameter.
 * @param species Parameter.
 * @param age Parameter.
 * @param weight Parameter.
 * @param type Parameter.
 * @param aviaryId Parameter.
 */
    Arachnid(const string& id, string& name, string& species, int age, double weight, const string& type, string& aviaryId);

/**
 * @brief Method makeSound.
 */
    void makeSound() const override;
/**
 * @brief Method move.
 */
    void move() const override;
};

#endif //ANIMALS_H
