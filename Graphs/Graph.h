/**
 * @file Graph.h
 * @author Denys Freyuk
 * @date 27.10.2025
 * @version 1.0
 * @brief Header for Graph declarations.
 */

#ifndef GRAPH_H
#define GRAPH_H
using namespace std;

#include <unordered_map>
#include <vector>
#include <memory>
#include <string>

/**
 * @class Vertex
 * @brief Represents the Vertex entity in the zoo management system.
 * @details This class is part of the Zoo Management project.
 */
/**
 * @example
 * Vertex* obj = nullptr; // Create or obtain an instance
 * // Use the public interface as needed.
 */

class Vertex {

private:
    string id;
public:
/**
 * @brief Method Vertex.
 */
    Vertex();
/**
 * @brief Method Vertex.
 * @param id Parameter.
 */
    explicit Vertex(const string& id);
/**
 * @brief Destructor ~Vertex.
 */
    virtual ~Vertex();
/**
 * @brief Method getId.
 * @return Result value.
 */
    string getId() const;
};

/**
 * @class Edge
 * @brief Represents the Edge entity in the zoo management system.
 * @details This class is part of the Zoo Management project.
 */
/**
 * @example
 * Edge* obj = nullptr; // Create or obtain an instance
 * // Use the public interface as needed.
 */

class Edge {

private:
    string fromId;
    string toId;
    double weight;
public:
    Edge(const string& from, const string& to, double w) : fromId(from), toId(to), weight(w) {}

/**
 * @brief Method getFrom.
 * @return Result value.
 */
    string getFrom() const;
/**
 * @brief Method getTo.
 * @return Result value.
 */
    string getTo() const;
/**
 * @brief Method getWeight.
 * @return Result value.
 */
    double getWeight() const;

};

/**
 * @class Graph
 * @brief Represents the Graph entity in the zoo management system.
 * @details This class is part of the Zoo Management project.
 */
/**
 * @example
 * Graph* obj = nullptr; // Create or obtain an instance
 * // Use the public interface as needed.
 */

class Graph {

private:
    unordered_map<string, shared_ptr<Vertex>> vertices;
    vector<Edge> edges;
protected:
/**
 * @brief Method getVertices.
 * @return Result value.
 */
    const unordered_map<string, shared_ptr<Vertex>>& getVertices() const;
/**
 * @brief Method getEdges.
 * @return Result value.
 */
    const vector<Edge>& getEdges() const;
/**
 * @brief Method getEdge.
 * @param fromId Parameter.
 * @param toId Parameter.
 * @return Result value.
 */
    const Edge* getEdge(const string& fromId, const string& toId) const;
/**
 * @brief Method getVertex.
 * @param id Parameter.
 * @return Result value.
 */
    shared_ptr<Vertex> getVertex(const string& id) const;
/**
 * @brief Method getNeighbors.
 * @param id Parameter.
 * @return Result value.
 */
    vector<string> getNeighbors(const string& id) const;

/**
 * @brief Method setVertices.
 * @param string Parameter.
 * @param newVertices Parameter.
 */
    void setVertices(const unordered_map<string, shared_ptr<Vertex>>& newVertices);
/**
 * @brief Method setEdges.
 * @param newEdges Parameter.
 */
    void setEdges(const vector<Edge>& newEdges);

/**
 * @brief Method addVertex.
 * @param v Parameter.
 */
    void addVertex(shared_ptr<Vertex> v);
/**
 * @brief Method addEdge.
 * @param fromId Parameter.
 * @param toId Parameter.
 * @param weight Parameter.
 */
    void addEdge(const string& fromId, const string& toId, double weight);

/**
 * @brief Method removeVertex.
 * @param id Parameter.
 */
    void removeVertex(const string& id);
/**
 * @brief Method removeEdge.
 * @param fromId Parameter.
 * @param toId Parameter.
 */
    void removeEdge(const string& fromId, const string& toId);

/**
 * @brief Method findPath.
 * @param startId Parameter.
 * @param endId Parameter.
 * @return Result value.
 */
    vector<string> findPath(const string& startId, const string& endId);
/**
 * @brief Method findPathByWeight.
 * @param startId Parameter.
 * @param endId Parameter.
 * @return Result value.
 */
    vector<string> findPathByWeight(const string& startId, const string& endId) const;
/**
 * @brief Method distanceBetween.
 * @param fromId Parameter.
 * @param toId Parameter.
 * @return Result value.
 */
    double distanceBetween(const std::string& fromId, const std::string& toId) const;

/**
 * @brief Method checkConnectivity.
 * @return Result value.
 */
    bool checkConnectivity() const;
/**
 * @brief Method printGraph.
 */
    void printGraph() const;
};
#endif //GRAPH_H
