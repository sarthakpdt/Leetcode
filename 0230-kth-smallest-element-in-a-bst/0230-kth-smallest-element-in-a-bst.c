/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void mergesort(int arr[],int left,int right){
	if (left<right){
		int mid=left+(right-left)/2;
		mergesort(arr,left,mid);
		mergesort(arr,mid+1,right);
		int n1=mid-left+1;
		int n2=right-mid;
		int larr[n1];
		int rarr[n2];
		for (int i=0;i<n1;i++){
			larr[i]=arr[left+i];
		}
		for (int i=0;i<n2;i++){
			rarr[i]=arr[mid+i+1];
		}
		int i=0;
		int j=0;
		int k=left;
		for (;i<n1 && j<n2;k++){
			if (larr[i]<rarr[j]){
				arr[k]=larr[i];
				i++;
			}
			else{
				arr[k]=rarr[j];
				j++;
			}
		}
		for (;i<n1;i++,k++){
			arr[k]=larr[i];
		}
		for (;j<n2;j++,k++){
			arr[k]=rarr[j];
		}
	}
}
int countnode(struct TreeNode *root){
	if (root==NULL){
		return 0;
	}
	return 1+countnode(root->left)+countnode(root->right);
	
}
void store(struct TreeNode *root,int array[],int *index){
    if (root==NULL){
        return;
    }
    array[*index]=root->val;
    (*index)++;
    store(root->left,array,index);
    store(root->right,array,index);
}
int kthSmallest(struct TreeNode* root, int k) {
    int count=countnode(root);
    int *array=(int *)malloc(count*sizeof(int));
    int index=0;
    store(root,array,&index);
    mergesort(array,0,count-1);
    int ans=array[k-1];
    return ans;
}