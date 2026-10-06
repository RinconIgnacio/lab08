#include "roster_io.h"

#include <fstream>
#include <sstream>

// TODO (Checkpoint 1): implement save_roster.
// Remove [[maybe_unused]] from a parameter once you use it.
bool save_roster([[maybe_unused]] const std::vector<Mech>& roster,
                 [[maybe_unused]] const std::string& path) {
    std::ofstream out(path);

    if (!out){
    return false;
}
    for (const Mech& mech : roster) {
        out << mech.name() << ","
            << mech.hp() << ","
            << mech.attack() << ","
            << mech.armor() << "\n";
    }

    return true;
}

// TODO (Checkpoints 2 and 3): implement load_roster.
bool load_roster([[maybe_unused]] const std::string& path,
                 [[maybe_unused]] std::vector<Mech>& roster,
                 [[maybe_unused]] int& skipped_lines) {
    std::ifstream in(path);
    
    if (!in) {
    return false;
}

    std::vector<Mech> loaded;
    skipped_lines = 0;
    std::string line;

    while (std::getline(in, line)) {
    std::istringstream fields(line);

    std::string name;
    std::string hp_text;
    std::string attack_text;
    std::string armor_text;

    if (!std::getline(fields, name, ',') ||
    !std::getline(fields, hp_text, ',') ||
    !std::getline(fields, attack_text, ',') ||
    !std::getline(fields, armor_text)) {
    ++skipped_lines;
    continue;
}

     int hp;
     int attack;
     int armor;

std::istringstream hp_stream(hp_text);
std::istringstream attack_stream(attack_text);
std::istringstream armor_stream(armor_text);

      if (!(hp_stream >> hp) ||
      !(attack_stream >> attack) ||
      !(armor_stream >> armor)) {
      ++skipped_lines;
      continue;
      }

   loaded.emplace_back(name, hp, attack, armor);
   }

   roster = loaded;
   return true;
    }

// TODO (Checkpoint 4): implement append_line.
bool append_line([[maybe_unused]] const std::string& path,
                 [[maybe_unused]] const std::string& text) {
    return false;
}
