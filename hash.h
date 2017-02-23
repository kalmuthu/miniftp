#ifndef _HASH_H_
#define _HASH_H_

typedef struct hash hash_t;													//����ѽṹ��¶������
typedef unsigned int (*hashfunc_t)(unsigned int, void*);					//��ϣ������Ͱ�ĸ��� �ؼ��룩���ݹؼ���õ�Ͱ�ĵ�ַ

hash_t* hash_alloc(unsigned int buckets, hashfunc_t hash_func);				//������ϣ��
void* hash_lookup_entry(hash_t *hash, void* key, unsigned int key_size);	//�ڹ�ϣ���в���
void hash_add_entry(hash_t *hash, void *key, unsigned int key_size,			//����ϣ�������һ��
	void *value, unsigned int value_size);
void hash_free_entry(hash_t *hash, void *key, unsigned int key_size);		//�ӹ�ϣ����ɾ��һ��


#endif /* _HASH_H_ */

