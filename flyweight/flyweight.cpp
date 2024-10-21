#include <iostream>
#include <unordered_map>
#include <vector>
#include <memory> // for shared_ptr

// Intrinsic properties
class TreeType {
public:
    std::string name;
    std::string color;
    std::string texture;

    TreeType(std::string name, std::string color, std::string texture) 
        : name(name), color(color), texture(texture) {}

    void draw(int x, int y) const {
        std::cout << "Drawing tree [" << name << "] at (" << x << ", " << y 
                  << ") with color [" << color << "] and texture [" << texture << "]." 
                  << std::endl;
    }
};

// Flyweight Factory
class TreeFactory {
    std::unordered_map<std::string, std::shared_ptr<TreeType>> treeTypes;

public:
    std::shared_ptr<TreeType> getTreeType(const std::string& name, const std::string& color, const std::string& texture) {
        std::string key = name + color + texture;
        if (treeTypes.find(key) == treeTypes.end()) {
            treeTypes[key] = std::make_shared<TreeType>(name, color, texture);
        }
        return treeTypes[key];
    }
};

// Extrinsic data
class Tree {
    int x, y;
    std::shared_ptr<TreeType> type;

public:
    Tree(int x, int y, std::shared_ptr<TreeType> type) 
        : x(x), y(y), type(type) {}

    void draw() const {
        type->draw(x, y);
    }
};

class Forest {
    std::vector<Tree> trees;
    TreeFactory treeFactory;

public:
    void plantTree(int x, int y, const std::string& name, const std::string& color, const std::string& texture) {
        std::shared_ptr<TreeType> type = treeFactory.getTreeType(name, color, texture);
        trees.emplace_back(Tree(x, y, type));
    }

    void drawForest() const {
        for (const auto& tree : trees) {
            tree.draw();
        }
    }
};

int main() {
    Forest forest;

    // Plant trees with shared TreeType (Flyweight)
    forest.plantTree(10, 20, "Oak", "Green", "Smooth");
    forest.plantTree(15, 25, "Pine", "Dark Green", "Rough");
    forest.plantTree(10, 20, "Oak", "Green", "Smooth");  // Reuses the existing Oak type

    forest.drawForest();
    return 0;
}
