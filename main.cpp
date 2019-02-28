#include <iostream>
#include <string>
#include <sstream>
#include <iterator>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

class Node
{
public:
    void setParam( Node* NL, Node* NR, int val ){
         nL = NL;
         nR = NR;
         value = val;
    }
        
public:
    Node *nL;
    Node *nR;
    int value;
};


vector<string> split(string str)
{
    std::istringstream iss(str);
    vector<string> result( (istream_iterator<string>(iss)), istream_iterator<string>() );
    return result;
}

int findExit( Node* node )
{
    if( node == NULL )return 0;
    if( findExit( node->nL ) > findExit( node->nR ) ) return node->value + findExit( node->nL );
    return node->value + findExit( node->nR );
}

int main()
{
    int N;
    cin >> N; cin.ignore();
    vector<Node*> nodes;
    for( int i = 0 ; i<N ; ++i )
    {
        nodes.push_back( new Node() );
    }
    
    for (int i( 0 ); i < N; ++i )
    {
        string item;
        getline( cin, item );
        vector<string> sss = split( item );
        
        Node* nodeL( NULL );
        Node* nodeR( NULL );
        
        if( sss[ 2 ] != "E" ) nodeL = nodes[ stoi( sss[ 2 ] ) ];
        if( sss[ 3 ] != "E" ) nodeR = nodes[ stoi( sss[ 3 ] ) ];
        nodes[ i ]->setParam( nodeL, nodeR, stoi(sss[ 1 ] ) );
    }

    cout << findExit(nodes[0]) << endl;
}