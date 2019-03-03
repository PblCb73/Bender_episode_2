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
    void setParam( Node* NL, Node* NR, int val){
         nL = NL;
         nR = NR;
         value = val;
         tempValue = val; 
    }
    
    void setNextValue( int v  )
    {
        if( value + v > tempValue ) 
        {
            tempValue = value + v;
            //value = 0;
        }
    }
        
public:
    Node *nL;
    Node *nR;
    int value;
    int tempValue;
    bool hasParent;
};


vector<string> split(string str)
{
    std::istringstream iss(str);
    vector<string> result( (istream_iterator<string>(iss)), istream_iterator<string>() );
    return result;
}


int main()
{
    int N;
    cin >> N; cin.ignore();
    vector<Node*> nodes;
    vector<Node*> exitNodes;
    for( int i = 0 ; i<N ; ++i )
    {
        nodes.push_back( new Node() );
    }
    
    for (int i( 0 ); i < N; ++i )
    {
        string item;
        getline( cin, item );
        vector<string> sss = split( item );
        cerr << item << endl;
        Node* nodeL( NULL );
        Node* nodeR( NULL );
        if( !nodes[ i ]->hasParent )
        {
            cerr<<"dont has parents:"<<i<<endl;
        }
        if( sss[ 2 ] != "E" )
        {
            nodeL = nodes[ stoi( sss[ 2 ] ) ];
            nodeL->hasParent = true;
            //nodeL->setNextValue(nodes[i]->tempValue);
        }
        if( sss[ 3 ] != "E" ) 
        {
            nodeR = nodes[ stoi( sss[ 3 ] ) ];
            nodeR->hasParent = true;
            //nodeR->setNextValue(nodes[i]->tempValue);
        }
        if( sss[ 2 ] == "E" or sss[ 3 ] == "E"  )
        {
            exitNodes.push_back( nodes[ i ] );
        }
        nodes[ i ]->setParam( nodeL, nodeR, stoi( sss[ 1 ] ) );
    }
    
    
    
    
    
    
    if( nodes[ 0 ]->nL != NULL )
    {
        nodes[ 0 ]->nL->setNextValue( nodes[ 0 ]->tempValue );// += nodes[i]->value;
    }
    if( nodes[ 0 ]->nR != NULL )
    {
        nodes[ 0 ]->nR->setNextValue( nodes[ 0 ]->tempValue );
    }
        
    for( int i = 1 ; i < nodes.size() ; i++ )
    {
        
        if( nodes[ i ]->nL != NULL )
        {
            nodes[ i ]->nL->hasParent = nodes[ i ]->hasParent;
            if( nodes[ i ]->nL->hasParent )
            {
                nodes[ i ]->nL->setNextValue( nodes[ i ]->tempValue );// += nodes[i]->value;
            }
        }
        if( nodes[ i ]->nR != NULL )
        {
            nodes[ i ]->nR->hasParent = nodes[ i ]->hasParent;
            if( nodes[ i ]->nR->hasParent )
            {
                nodes[ i ]->nR->setNextValue( nodes[ i ]->tempValue );
            }
        }
    }
    
    int summ = 0;
    for( int i(0) ; i<exitNodes.size() ; i++ )
    {
        if(summ<exitNodes[i]->tempValue)
        {
            summ = exitNodes[i]->tempValue;
        }
        cerr<<"  "<<exitNodes[i]->hasParent<<"  "<<exitNodes[i]->tempValue<<endl;
    }
    cout << summ << endl;
    
}