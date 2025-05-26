#include "generator.h"

const std::vector<std::string> Generator::first_names = {
    "Eligijus",
    "Jonas",
    "Vytautas",
    "Antanas",
    "Tomas",
    "Juozas",
    "Ona",
    "Irena",
    "Janina",
    "Kristina",
    "Danute"
};

const std::vector<std::string> Generator::last_names = {
    "Alencikas",
    "Jodikevicius",
    "Jasiunskas",
    "Stasiulionis",
    "Budvila",
    "Davailis",
    "Ignataitis",
    "Girla",
    "Numeika",
    "Kabaila",
    "Milakna"
};

std::string Generator::gen_f_name() {
    return first_names[rand() % first_names.size()];
}

std::string Generator::gen_l_name() {
    return last_names[rand() % last_names.size()];
}

std::string Generator::gen_name() {
    return first_names[rand() % first_names.size()] + " " + last_names[rand() % last_names.size()];
}

std::vector<std::string> Generator::gen_names(unsigned long num_of_name) const {
    std::vector<std::string> names;
    for (unsigned long i = 0; i < num_of_name; i++) {
        names.push_back(gen_name());
    }
    return names;
}

int Generator::rand_int(const int min, const int max) {
    return min + (rand() % (max - min + 1));
}