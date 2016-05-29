/*�������������һ���������Сֵ�������������������õģ���Ŀ�е�sorted�����Ǽٶ�����������ģ�Ȼ��Դ������е�ĳһ��
Ԫ�ؽ�����ת����������������С��Ԫ����ʲô������ԭ��������[0,1,2,3,4],�����[3,4,0,1,2]���ҵ�0�����ˡ����ظ�Ԫ�ء�*/

class Solution {
public:
    int findMin(vector<int>& nums) {
/*�ö��ַ�������Ϊʲô������ö��ַ������أ�ʵ�����⻹����һ��Ԫ�ص����⣬ֻ�������鲻�ǳ�����������ѣ����������룬����
����������Ԫ��ֵС��ĩԪ��ֵ����ô���������Ѿ���������ˣ���������ת�ˣ���СԪ�ؾ��ǵ�һ��Ԫ�ء����粻�������أ�
��ô������������������[3,4,0,1,2]������������ֳ�������[3,4]��[0,1,2]�����һ��ȡ�м�Ԫ�أ���ֵ���ڻ���ڵ�һ��
Ԫ�أ��򻹴��ڵ�һ���֣���ô��Ҫ��start��Ϊmid+1����ΪСԪ�ػ��ں��棬����Ҫע����ںţ���Ϊ��Ҫ����[2,1]�����������
startԪ�غ�midֵһ��������������Ҫȥ�Һ����Ԫ�ء���������м�Ԫ��С�ڵ�һ��Ԫ�أ���ô���Ԫ���п�������С�ģ�Ҳ�п���������
֮ǰ�ģ�����Ҫ��end��Ϊmidֵ��*/
        int len = nums.size();

            int a = 0;
            int b = len - 1;

            while(a < b){
                if(nums[a] < nums[b])
                    return nums[a];
                int mid = (a+b)/2;
                if(nums[mid] >= nums[a]) //���1
                    a = mid + 1;
                else                    //���2
                    b = mid;
            }
            return nums[a];

        }

};