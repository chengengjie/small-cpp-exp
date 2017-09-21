// Check reference type of auto deduction

#include <iostream>
#include <vector>

using namespace std;

class Node
{
public:
    Node()
    {
        id = globalId++;
        cout << "\tconstruct node " << id << endl;
    }

    Node(const Node& rhs)
    {
        id = rhs.id;
        cout << "\tcopy construct node " << id << endl;
    }

    ~Node()
    {
        cout << "\tdestruct node " << id << endl;
    }

    int id;
    static int globalId;
};

int Node::globalId;

class NodeFactory
{
public:
    NodeFactory()
    {
        _nodes.reserve(32);
    }

    auto GetNodeRvalue()
    {
        return Node();
    }

    auto GetNode()
    {
        _nodes.emplace_back();
        return _nodes.back();
    }

    auto& GetNodeRef()
    {
        _nodes.emplace_back();
        return _nodes.back();
    }

private:
    vector<Node> _nodes;
};

int main()
{
    {
        Node::globalId = 0;
        cout << "Test GetNodeRvalue..." << endl;
        NodeFactory nodeFactory;
        cout << "first" << endl;
        auto node1 = nodeFactory.GetNodeRvalue();
        // auto& node2 = nodeFactory.GetNode();     // invalid syntax
        cout << "second" << endl;
        auto&& node3 = nodeFactory.GetNodeRvalue();
        cout << "final" << endl;
    }

    {
        Node::globalId = 0;
        cout << endl << "Test GetNode..." << endl;
        NodeFactory nodeFactory;
        cout << "first" << endl;
        auto node1 = nodeFactory.GetNode();         // copy!!!
        // auto& node2 = nodeFactory.GetNode2();    // invalid syntax
        cout << "second" << endl;
        auto&& node3 = nodeFactory.GetNode();       // copy!!!
        cout << "final" << endl;
    }

    {
        Node::globalId = 0;
        cout << endl << "Test GetNodeRef..." << endl;
        NodeFactory nodeFactory;
        cout << "first" << endl;
        auto node1 = nodeFactory.GetNodeRef();      // copy!!!
        cout << "second" << endl;
        auto& node2 = nodeFactory.GetNodeRef();
        cout << "third" << endl;
        auto&& node3 = nodeFactory.GetNodeRef();
        cout << "final" << endl;
    }

    return 0;
}