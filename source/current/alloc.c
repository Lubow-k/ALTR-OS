#define NULL (void*)0

typedef char byte;
typedef unsigned int u32;


const u32 BLOCK_SIZE = 1024;            // set according to needs
u32 amount_of_blocks = 3 * 1024;        // BLOCK_SIZE * amount_of_blocks = 3 MB   
void* block_head = NULL;
void* list_head = NULL;


typedef struct {
	void* next;
}list;


void* _malloc(u32 len) {
	if (len > BLOCK_SIZE) {
		return NULL;
	}
	if (amount_of_blocks > 0) {
		amount_of_blocks--;
		void* a = block_head;
		block_head = (void*)((byte*)block_head + BLOCK_SIZE);
		return a;
	}
	else if (list_head) {
		void* a = list_head;
		list_head = ((list*)list_head)->next;
		return a;
	}
	return NULL;
}

void _free(void* ptr) {
	void* buff = list_head;
	list_head = ptr;
	((list*)list_head)->next = buff;
}

void* _realloc(void* ptr, u32 len) {
	if (len > BLOCK_SIZE) {
		return NULL;
	}
	return ptr;
}

void* _calloc(u32 len, u32 size) {
	void* a = _malloc(len * size);
	for (u32 i = 0; i < len * size; i++) {
		*((byte*)a + i) = 0;
	}
	return a;
}

void* init_allocator() {
	void* alloc = (void*) 0x100000;
	block_head = alloc;
	return alloc;
}

