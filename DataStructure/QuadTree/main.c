/*
 This program is make the 42 random point include (1,23), (3,15), and make the quadtree.
 Tree making will be contined until every points included unique rectangle.
 Tree making function will proceed reculsive. And every node will be visitd in preorder.
 Generate the random rectangle and find the all points included.
 
 It is clockwise, from quadrant 1 (NW)-(NE)-(SE)-(SW)
 
 2014/04/18, Made by 우영남.
 
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct rectangle rectangle;
typedef struct point point;
typedef struct qnode qnode;

struct rectangle{ // It is struct of rectangle data.
    double top_left_x;
    double top_left_y;
    double width;
    double height;
};

struct point{ // It is struct of point data.
    double point_x;
    double point_y;
};

struct qnode{ // It is struct of node data.
    rectangle input_rectangle;
    int tree_level;
    qnode* first_child;
    qnode* second_child;
    qnode* third_child;
    qnode* fourth_child;
    double leaf_x;
    double leaf_y;
};


int point_num=42;
point p[42];
double temp_leaf_x; // location of x, if one rectangle contains one point.
double temp_leaf_y; // location of y, if one rectangle contains one point.

void region_search(qnode* parent, rectangle* g_rectangle); // function declaraion of 'region_search'
void finding_two_point(); // function declaraion of finding_two_point that include (1,23), (3,15)
void point_generate(); // function declaraion of point_generate
int get_rand(int num); // function declaraion of get_rand
void preorder_trav(qnode* parent); // preorder traversal funtion declaration
void makeQuadTree(qnode* parent, int t_level); // function declaraion of makeQueadTree
int count_point(qnode* checked_node); // function declaraion of count_point

int main(void){
    
    int tree_level = 1;
    int i;
    
    srand((unsigned)time(NULL));
    
    //genterate the 42 random points include (3,15) (1,23).
    point_generate();
    
    printf("1. <Printing all points>\n");
    for(int i=0; i<point_num; i++){
        printf("(%.0lf, %.0lf)\n",p[i].point_x, p[i].point_y);
    }
    printf("\n");
    
    
    //make the root node and set the initial rectangle data.
    qnode* root = (qnode*)malloc(sizeof(qnode)*1);
    root->input_rectangle.top_left_x = 0;
    root->input_rectangle.top_left_y = 32;
    root->input_rectangle.width = 32;
    root->input_rectangle.height = 32;
    
    
    makeQuadTree(root, tree_level);
    
    //print all data in tree.
    printf("2. <Printing each leaf node in preorder>\n");
    preorder_trav(root);
    printf("\n");
    
    //Rectangle data of (3,15), (1,23)
    printf("3. <Rectangle data of (3,15), (1,23)>\n");
    finding_two_point(root);
    printf("\n\n");
    
    //Region search
    printf("4. <Region search>\n");
    
    for(i=0; i<4; i++){ // generate the 4 random tree and finding included points
        rectangle region;
        int condition_check=0;
        
        while(condition_check==0){ // while loop : check the conditions that top left, width, height
            condition_check=1;
            
            region.top_left_x = get_rand(32);
            region.top_left_y = get_rand(30);
            region.width = get_rand(24);
            region.height = get_rand(24);
            
            if(((int)region.top_left_x%2==1) || ((int)region.top_left_y%2==1) || (region.top_left_x<4) || (region.top_left_y<4) || ((int)region.width%2==1) || ((int)region.height%2==1) || (region.width<2) || (region.height<2)){
                condition_check=0;
            }
        }
        
        printf("- generated rectangle data - \n");
        printf("Top left : (%.0lf, %.0lf)\nWidth : %.0lf\nHeight: %.0lf\n",region.top_left_x, region.top_left_y, region.width, region.height);
        printf("- included points - \n");
        
        region_search(root, &region);
        printf("\n");
    }
}

/*
 It recieve the node pointer, tree level and make the quad tree.
 check how many points contained in rectangle.
 
 It is reculsive function.
 
 SIMPLE ALGORITHM
 //
 Count the included points using for loop
 If contained point == 1
 Then, insert the location of point into a node.
 Return.
 
 If contained points > 1
 Make the q1(NW) rectangle and new node that first child.
 Call makeNodes(q1 node).
 
 Make the q2(NE) rectangle and new node that second child.
 Call makeNodes(q2 node).
 
 Make the q3(SE) rectangle and new node that third child.
 Call makeNodes(q3 node).
 
 Make the q4(SW) rectangle and new node that fourth child.
 Call makeNodes(q4 node).
 
 If there are no points in a rectangle
 Then, return.
 //
 
 Input : root node pointer, tree level
 Output : none
 */
void makeQuadTree(qnode* parent, int t_level){
    int included_point = count_point(parent);
    
    if(included_point == 1){
        parent->tree_level = t_level;
        parent->leaf_x = temp_leaf_x;
        parent->leaf_y = temp_leaf_y;
    }
    
    else if(included_point > 1){
        parent->tree_level = t_level;
        
        qnode* q1 = (qnode*)malloc(sizeof(qnode)*1);
        q1->input_rectangle.width = parent->input_rectangle.width/2;
        q1->input_rectangle.height = parent->input_rectangle.height/2;
        q1->input_rectangle.top_left_x = parent->input_rectangle.top_left_x;
        q1->input_rectangle.top_left_y = parent->input_rectangle.top_left_y;
        parent->first_child = q1;
        if(q1->input_rectangle.height>=2 && q1->input_rectangle.width>=2){//If width and height of generated rectangle less than 2, not call the function
            makeQuadTree(q1, t_level+1);
        }
        
        
        qnode* q2 = (qnode*)malloc(sizeof(qnode)*1);
        q2->input_rectangle.width = parent->input_rectangle.width/2;
        q2->input_rectangle.height = parent->input_rectangle.height/2;
        q2->input_rectangle.top_left_x = parent->input_rectangle.top_left_x + (parent->input_rectangle.width/2);
        q2->input_rectangle.top_left_y = parent->input_rectangle.top_left_y;
        parent->second_child = q2;
        if(q2->input_rectangle.height>=2 && q2->input_rectangle.width>=2){
            makeQuadTree(q2, t_level+1);
        }
        
        
        qnode* q3 = (qnode*)malloc(sizeof(qnode)*1);
        q3->input_rectangle.width = parent->input_rectangle.width/2;
        q3->input_rectangle.height = parent->input_rectangle.height/2;
        q3->input_rectangle.top_left_x = parent->input_rectangle.top_left_x + (parent->input_rectangle.width/2);
        q3->input_rectangle.top_left_y = parent->input_rectangle.top_left_y - (parent->input_rectangle.height/2);
        parent->third_child = q3;
        if(q3->input_rectangle.height>=2 && q3->input_rectangle.width>=2){
            makeQuadTree(q3, t_level+1);
        }
        
        
        qnode* q4 = (qnode*)malloc(sizeof(qnode)*1);
        q4->input_rectangle.width = parent->input_rectangle.width/2;
        q4->input_rectangle.height = parent->input_rectangle.height/2;
        q4->input_rectangle.top_left_x = parent->input_rectangle.top_left_x;
        q4->input_rectangle.top_left_y = parent->input_rectangle.top_left_y - (parent->input_rectangle.height/2);
        parent->fourth_child = q4;
        if(q4->input_rectangle.height>=2 && q4->input_rectangle.width>=2){
            makeQuadTree(q4, t_level+1);
        }
        
    }
    
    else if(included_point == 0){
        parent->tree_level = t_level;
    }
    
}

/*
 It is recieve the generated rectangle, root node and find which point contained in preorder.
 
 Input : root node pointer, generated rectangle pointer.
 Output : none.
 */
void region_search(qnode* parent, rectangle* g_rectangle){
    
    rectangle region = *g_rectangle;
    
    if(parent != NULL){
        if(((region.top_left_x < parent->leaf_x) && (parent->leaf_x < region.top_left_x + region.width)) && ((region.top_left_y - region.height < parent->leaf_y) && (parent->leaf_y < region.top_left_y))){
            printf("(%.0lf, %.0lf)\n",parent->leaf_x, parent->leaf_y);
        }
        
        region_search(parent->first_child,g_rectangle);
        region_search(parent->second_child,g_rectangle);
        region_search(parent->third_child,g_rectangle);
        region_search(parent->fourth_child,g_rectangle);
        
    }
}


/*
 It is recieve the specific node and counting how many points contained.
 And temp variable will be saved in leaf node.
 
 Input : node pointer.
 Output : contained point number.
 */
int count_point(qnode* checked_node){
    int i;
    int count=0;
    
    for(i=0; i<point_num; i++){
        if(((checked_node->input_rectangle.top_left_x < p[i].point_x) && (p[i].point_x < checked_node->input_rectangle.top_left_x + checked_node->input_rectangle.width)) && ((checked_node->input_rectangle.top_left_y - checked_node->input_rectangle.height < p[i].point_y) && (p[i].point_y < checked_node->input_rectangle.top_left_y))){
            
            //If it is one point in a rectangle, it will be saved in leaf node.
            temp_leaf_x = p[i].point_x;
            temp_leaf_y = p[i].point_y;
            
            count++;
        }
    }
    
    return count;
}

/*
 It is preorder traversal function.
 Print the location of point, if it is leaf node.
 
 Input : root node pointer.
 Output : none.
 */
void preorder_trav(qnode* parent){
    if(parent != NULL ) {
        
        if(parent->leaf_x!=0 && parent->leaf_y!=0){
            printf("(%.0lf, %.0lf)[lv.%d]\n",parent->leaf_x, parent->leaf_y, parent->tree_level);
        }
        preorder_trav(parent->first_child);
        preorder_trav(parent->second_child);
        preorder_trav(parent->third_child);
        preorder_trav(parent->fourth_child);
    }
}

/*
 It is print the rectangle data contains (3, 15), (1, 23).
 It uses preorder traversal.
 
 Input : root node pointer.
 Output : none.
 */
void finding_two_point(qnode* parent){
    if(parent != NULL ) {
        
        if((parent->leaf_x==3 && parent->leaf_y==15) || (parent->leaf_x==1 && parent->leaf_y==23)){
            printf("- point(%.0lf, %.0lf) -\n",parent->leaf_x,parent->leaf_y);
            printf("Top left : (%.0lf, %.0lf)\nWidth : %.0lf\nHeight: %.0lf\n\n",parent->input_rectangle.top_left_x, parent->input_rectangle.top_left_y, parent->input_rectangle.width, parent->input_rectangle.height);
        }
        finding_two_point(parent->first_child);
        finding_two_point(parent->second_child);
        finding_two_point(parent->third_child);
        finding_two_point(parent->fourth_child);
    }
}

/*
 It is generate the 42 random point include (3, 15), (1, 23).
 And check the given condition.
 
 Input : none
 Output :none (only make the random number and insert into global variable.)
 */
void point_generate(){
    int i, j;
    int rand_x=0;
    int rand_y=0;
    int check_dup=0;
    
    p[0].point_x = 3; p[0].point_y = 15;
    p[1].point_x = 1; p[1].point_y = 23;
    
    for(i=2; i<point_num; i++){
        check_dup=0;
        rand_x = get_rand(31);
        rand_y = get_rand(31);
        
        if((rand_x%2==0) || (rand_y%2 == 0)){//If it is odd number, generate again.
            i--;
            continue;
        }
        
        for(j=0; j<point_num; j++){ // If generated point is already existed, repeat the generation.
            if((p[j].point_x == rand_x) && (p[j].point_y == rand_y)){
                i--;
                check_dup=1;
                break;
            }
        }
        
        if(check_dup==0){
            p[i].point_x = rand_x;
            p[i].point_y = rand_y;
        }
        
    }
    
}

/*
 It is function of generate number within parameter.
 
 Input : limit number.
 Ouput : random number.
 */
int get_rand(int num){
    int result=0;
    
    
    result = 1 + ((int)rand()%num);
    return result;
}
