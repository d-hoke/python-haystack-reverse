// Generated by pdbparse v1.1 - -g -w 8 -d heap.structures.win7.2 /home/other/outputs/pdb/Win7SP1X64/_000143D

/******* Define basic Windows types *******/

// If compiling with gcc, use -fms-extensions

#include <stdint.h>

typedef  uint8_t     UINT8;
typedef  uint8_t     UCHAR;
typedef  uint8_t      BOOL;

typedef   int8_t      CHAR;
typedef   int8_t      INT8;

typedef uint16_t     WCHAR;
typedef uint16_t    UINT16;
typedef uint16_t    USHORT;
typedef  int16_t     SHORT;

typedef uint32_t    UINT32;
typedef uint32_t     ULONG;
typedef  int32_t      LONG;

typedef uint64_t    UINT64;
typedef uint64_t ULONGLONG;
typedef  int64_t  LONGLONG;

typedef uint64_t   PVOID64, PPVOID64;
typedef uint32_t   PVOID32, PPVOID32;
typedef     void      VOID;

typedef  double     DOUBLE; // not true but -hey FIXME

#ifdef WINDOWS_USE_32_BIT_POINTERS ///////////////
// pointers occupy exactly 32 bits
typedef  UINT32     PUINT8;
typedef  UINT32     PUCHAR;
typedef  UINT32      PBOOL;

typedef  UINT32      PCHAR;
typedef  UINT32      PINT8;

typedef  UINT32    PUINT16;
typedef  UINT32    PUSHORT;
typedef  UINT32     PSHORT;

typedef  UINT32     PUINT32;
typedef  UINT32      PULONG;
typedef  UINT32       PLONG;

typedef  UINT32     PUINT64;
typedef  UINT32  PULONGLONG;
typedef  UINT32   PLONGLONG;

typedef  UINT32       PVOID, PPVOID;

#else /////////////////  !WINDOWS_USE_32_BIT_POINTERS
// pointers occupy native address width per ABI
typedef     UINT8     *PUINT8;
typedef     UCHAR     *PUCHAR;
typedef      BOOL      *PBOOL;

typedef      CHAR      *PCHAR;
typedef      INT8      *PINT8;

typedef    UINT16    *PUINT16;
typedef    USHORT    *PUSHORT;
typedef     SHORT     *PSHORT;

typedef    UINT32    *PUINT32;
typedef     ULONG     *PULONG;
typedef      LONG      *PLONG;

typedef    UINT64    *PUINT64;
typedef ULONGLONG *PULONGLONG;
typedef  LONGLONG  *PLONGLONG;

typedef      VOID      *PVOID, **PPVOID;

#endif /////////////////  WINDOWS_USE_32_BIT_POINTERS

#define P(basetype, var) ( (basetype *)(var))

/******* circular dependencies *******/
struct _HEAP;
typedef struct _HEAP HEAP;
typedef HEAP *PHEAP, **PPHEAP;

struct _HEAP_LOCAL_DATA;
typedef struct _HEAP_LOCAL_DATA HEAP_LOCAL_DATA;
typedef HEAP_LOCAL_DATA *PHEAP_LOCAL_DATA, **PPHEAP_LOCAL_DATA;

struct _HEAP_LOCAL_SEGMENT_INFO;
typedef struct _HEAP_LOCAL_SEGMENT_INFO HEAP_LOCAL_SEGMENT_INFO;
typedef HEAP_LOCAL_SEGMENT_INFO *PHEAP_LOCAL_SEGMENT_INFO, **PPHEAP_LOCAL_SEGMENT_INFO;

struct _HEAP_LOCK;
typedef struct _HEAP_LOCK HEAP_LOCK;
typedef HEAP_LOCK *PHEAP_LOCK, **PPHEAP_LOCK;

struct _HEAP_SUBSEGMENT;
typedef struct _HEAP_SUBSEGMENT HEAP_SUBSEGMENT;
typedef HEAP_SUBSEGMENT *PHEAP_SUBSEGMENT, **PPHEAP_SUBSEGMENT;

struct _HEAP_USERDATA_HEADER;
typedef struct _HEAP_USERDATA_HEADER HEAP_USERDATA_HEADER;
typedef HEAP_USERDATA_HEADER *PHEAP_USERDATA_HEADER, **PPHEAP_USERDATA_HEADER;

struct _LFH_HEAP;
typedef struct _LFH_HEAP LFH_HEAP;
typedef LFH_HEAP *PLFH_HEAP, **PPLFH_HEAP;

struct _RTL_CRITICAL_SECTION;
typedef struct _RTL_CRITICAL_SECTION RTL_CRITICAL_SECTION;
typedef RTL_CRITICAL_SECTION *PRTL_CRITICAL_SECTION, **PPRTL_CRITICAL_SECTION;

struct _RTL_CRITICAL_SECTION_DEBUG;
typedef struct _RTL_CRITICAL_SECTION_DEBUG RTL_CRITICAL_SECTION_DEBUG;
typedef RTL_CRITICAL_SECTION_DEBUG *PRTL_CRITICAL_SECTION_DEBUG, **PPRTL_CRITICAL_SECTION_DEBUG;

/******* Enumerations *******/
/*******  Structures  *******/
typedef struct _LIST_ENTRY { // 0x10 bytes
	struct _LIST_ENTRY*  Flink;                       // offset   0x0 size   0x8
	struct _LIST_ENTRY*  Blink;                       // offset   0x8 size   0x8

} __attribute__((packed)) LIST_ENTRY, *PLIST_ENTRY, **PPLIST_ENTRY ;

typedef union _SLIST_HEADER { // 0x10 bytes
	struct {
		ULONGLONG Alignment;                             // offset   0x0 size   0x8
		ULONGLONG Region;                                // offset   0x8 size   0x8
	};
	struct {
	struct { // bitfield(s)
ULONGLONG Depth : 16;                              // offset     0 size   2.0
ULONGLONG Sequence : 9;                            // offset   2.0 [0x2] size 1.125
ULONGLONG NextEntry : 39;                          // offset 3.125 size 4.875
ULONGLONG HeaderType : 1;                          // offset   8.0 [0x8] size 0.125
ULONGLONG Init : 1;                                // offset 8.125 size 0.125
ULONGLONG Reserved : 59;                           // offset  8.25 size 7.375
ULONGLONG Region : 3;                              // offset 15.625 size 0.375
};
} Header8; // offset   0x0 size  0x10
	struct {
	struct { // bitfield(s)
ULONGLONG Depth : 16;                              // offset     0 size   2.0
ULONGLONG Sequence : 48;                           // offset   2.0 [0x2] size   6.0
ULONGLONG HeaderType : 1;                          // offset   8.0 [0x8] size 0.125
ULONGLONG Init : 1;                                // offset 8.125 size 0.125
ULONGLONG Reserved : 2;                            // offset  8.25 size  0.25
ULONGLONG NextEntry : 60;                          // offset   8.5 size   7.5
};
} Header16; // offset   0x0 size  0x10
	struct {
		struct {
	struct { // bitfield(s)
ULONGLONG Depth : 16;                              // offset     0 size   2.0
ULONGLONG Sequence : 48;                           // offset   2.0 [0x2] size   6.0
ULONGLONG HeaderType : 1;                          // offset   8.0 [0x8] size 0.125
ULONGLONG Reserved : 3;                            // offset 8.125 size 0.375
ULONGLONG NextEntry : 60;                          // offset   8.5 size   7.5
};
} HeaderX64; // offset   0x0 size  0x10
	};

} __attribute__((packed)) SLIST_HEADER, *PSLIST_HEADER, **PPSLIST_HEADER ;

typedef struct _SINGLE_LIST_ENTRY { // 0x8 bytes
	struct _SINGLE_LIST_ENTRY*  Next;                 // offset   0x0 size   0x8

} __attribute__((packed)) SINGLE_LIST_ENTRY, *PSINGLE_LIST_ENTRY, **PPSINGLE_LIST_ENTRY ;

typedef struct _HEAP_TAG_ENTRY { // 0x48 bytes
	ULONG Allocs;                                     // offset   0x0 size   0x4
	ULONG Frees;                                      // offset   0x4 size   0x4
	ULONGLONG Size;                                   // offset   0x8 size   0x8
	USHORT TagIndex;                                  // offset  0x10 size   0x2
	USHORT CreatorBackTraceIndex;                     // offset  0x12 size   0x2
	WCHAR TagName[0x18];                              // offset  0x14 size  0x30
	UINT8 gap_in_pdb_ofs_44[0x4];                     // offset  0x44 size   0x4

} __attribute__((packed)) HEAP_TAG_ENTRY, *PHEAP_TAG_ENTRY, **PPHEAP_TAG_ENTRY ;

typedef union _HEAP_BUCKET_COUNTERS { // 0x8 bytes
	struct {
		volatile ULONG TotalBlocks;                      // offset   0x0 size   0x4
		volatile ULONG SubSegmentCounts;                 // offset   0x4 size   0x4
	};
	struct {
		volatile LONGLONG Aggregate64;                   // offset   0x0 size   0x8
	};

} __attribute__((packed)) HEAP_BUCKET_COUNTERS, *PHEAP_BUCKET_COUNTERS, **PPHEAP_BUCKET_COUNTERS ;

typedef union _HEAP_BUCKET_RUN_INFO { // 0x8 bytes
	struct {
		volatile ULONG Bucket;                           // offset   0x0 size   0x4
		volatile ULONG RunLength;                        // offset   0x4 size   0x4
	};
	struct {
		volatile LONGLONG Aggregate64;                   // offset   0x0 size   0x8
	};

} __attribute__((packed)) HEAP_BUCKET_RUN_INFO, *PHEAP_BUCKET_RUN_INFO, **PPHEAP_BUCKET_RUN_INFO ;

typedef struct _INTERLOCK_SEQ { // 0x8 bytes
union {
	struct {
		USHORT Depth;                                    // offset   0x0 size   0x2
		USHORT FreeEntryOffset;                          // offset   0x2 size   0x2
	};
	struct {
		volatile ULONG OffsetAndDepth;                   // offset   0x0 size   0x4
		volatile ULONG Sequence;                         // offset   0x4 size   0x4
	};
	struct {
		volatile LONGLONG Exchg;                         // offset   0x0 size   0x8
	};
};
} __attribute__((packed)) INTERLOCK_SEQ, *PINTERLOCK_SEQ, **PPINTERLOCK_SEQ ;

typedef struct _HEAP_BUCKET { // 0x4 bytes
	USHORT BlockUnits;                                // offset   0x0 size   0x2
	UCHAR SizeIndex;                                  // offset   0x2 size   0x1
	struct { // bitfield(s)
UCHAR UseAffinity : 1;                             // offset     3 [0x3] size 0.125
UCHAR DebugFlags : 2;                              // offset 3.125 size  0.25
};

} __attribute__((packed)) HEAP_BUCKET, *PHEAP_BUCKET, **PPHEAP_BUCKET ;

typedef struct _HEAP_COUNTERS { // 0x70 bytes
	ULONGLONG TotalMemoryReserved;                    // offset   0x0 size   0x8
	ULONGLONG TotalMemoryCommitted;                   // offset   0x8 size   0x8
	ULONGLONG TotalMemoryLargeUCR;                    // offset  0x10 size   0x8
	ULONGLONG TotalSizeInVirtualBlocks;               // offset  0x18 size   0x8
	ULONG TotalSegments;                              // offset  0x20 size   0x4
	ULONG TotalUCRs;                                  // offset  0x24 size   0x4
	ULONG CommittOps;                                 // offset  0x28 size   0x4
	ULONG DeCommitOps;                                // offset  0x2c size   0x4
	ULONG LockAcquires;                               // offset  0x30 size   0x4
	ULONG LockCollisions;                             // offset  0x34 size   0x4
	ULONG CommitRate;                                 // offset  0x38 size   0x4
	ULONG DecommittRate;                              // offset  0x3c size   0x4
	ULONG CommitFailures;                             // offset  0x40 size   0x4
	ULONG InBlockCommitFailures;                      // offset  0x44 size   0x4
	ULONG CompactHeapCalls;                           // offset  0x48 size   0x4
	ULONG CompactedUCRs;                              // offset  0x4c size   0x4
	ULONG AllocAndFreeOps;                            // offset  0x50 size   0x4
	ULONG InBlockDeccommits;                          // offset  0x54 size   0x4
	ULONGLONG InBlockDeccomitSize;                    // offset  0x58 size   0x8
	ULONGLONG HighWatermarkSize;                      // offset  0x60 size   0x8
	ULONGLONG LastPolledSize;                         // offset  0x68 size   0x8

} __attribute__((packed)) HEAP_COUNTERS, *PHEAP_COUNTERS, **PPHEAP_COUNTERS ;

typedef struct _HEAP_PSEUDO_TAG_ENTRY { // 0x10 bytes
	ULONG Allocs;                                     // offset   0x0 size   0x4
	ULONG Frees;                                      // offset   0x4 size   0x4
	ULONGLONG Size;                                   // offset   0x8 size   0x8

} __attribute__((packed)) HEAP_PSEUDO_TAG_ENTRY, *PHEAP_PSEUDO_TAG_ENTRY, **PPHEAP_PSEUDO_TAG_ENTRY ;

typedef struct _HEAP_ENTRY { // 0x10 bytes
union {
	struct {
		PVOID64 PreviousBlockPrivateData;                // offset   0x0 size   0x8
		union {
			struct {
				USHORT Size;                                   // offset   0x8 size   0x2
				UCHAR Flags;                                   // offset   0xa size   0x1
				UCHAR SmallTagIndex;                           // offset   0xb size   0x1
				USHORT PreviousSize;                           // offset   0xc size   0x2
				union {
					UCHAR SegmentOffset;                          // offset   0xe size   0x1
					UCHAR LFHFlags;                               // offset   0xe size   0x1
				};
				UCHAR UnusedBytes;                             // offset   0xf size   0x1
			};
			struct {
				ULONGLONG CompactHeader;                       // offset   0x8 size   0x8
			};
		};
	};
	struct {
		PVOID64 Reserved;                                // offset   0x0 size   0x8
		union {
			struct {
				USHORT FunctionIndex;                          // offset   0x8 size   0x2
				USHORT ContextValue;                           // offset   0xa size   0x2
			};
			ULONG InterceptorValue;                         // offset   0x8 size   0x4
		};
		USHORT UnusedBytesLength;                        // offset   0xc size   0x2
		UCHAR EntryOffset;                               // offset   0xe size   0x1
		UCHAR ExtendedBlockSignature;                    // offset   0xf size   0x1
	};
	struct {
		PVOID64 ReservedForAlignment;                    // offset   0x0 size   0x8
		union {
			struct {
				ULONG Code1;                                   // offset   0x8 size   0x4
				USHORT Code2;                                  // offset   0xc size   0x2
				UCHAR Code3;                                   // offset   0xe size   0x1
				UCHAR Code4;                                   // offset   0xf size   0x1
			};
			struct {
				ULONGLONG AgregateCode;                        // offset   0x8 size   0x8
			};
		};
	};
};
} __attribute__((packed)) HEAP_ENTRY, *PHEAP_ENTRY, **PPHEAP_ENTRY ;

typedef struct _HEAP_TUNING_PARAMETERS { // 0x10 bytes
	ULONG CommittThresholdShift;                      // offset   0x0 size   0x4
	UINT8 gap_in_pdb_ofs_4[0x4];                      // offset   0x4 size   0x4
	ULONGLONG MaxPreCommittThreshold;                 // offset   0x8 size   0x8

} __attribute__((packed)) HEAP_TUNING_PARAMETERS, *PHEAP_TUNING_PARAMETERS, **PPHEAP_TUNING_PARAMETERS ;

typedef struct _LFH_BLOCK_ZONE { // 0x20 bytes
	LIST_ENTRY ListEntry;                             // offset   0x0 size  0x10
	PVOID FreePointer;                                // offset  0x10 size   0x8
	PVOID64 Limit;                                    // offset  0x18 size   0x8

} __attribute__((packed)) LFH_BLOCK_ZONE, *PLFH_BLOCK_ZONE, **PPLFH_BLOCK_ZONE ;

typedef struct _USER_MEMORY_CACHE_ENTRY { // 0x20 bytes
	SLIST_HEADER UserBlocks;                          // offset   0x0 size  0x10
	ULONG AvailableBlocks;                            // offset  0x10 size   0x4
	UINT8 gap_in_pdb_ofs_14[0xc];                     // offset  0x14 size   0xc

} __attribute__((packed)) USER_MEMORY_CACHE_ENTRY, *PUSER_MEMORY_CACHE_ENTRY, **PPUSER_MEMORY_CACHE_ENTRY ;

typedef struct _RTL_CRITICAL_SECTION { // 0x28 bytes
	PRTL_CRITICAL_SECTION_DEBUG DebugInfo;            // offset   0x0 size   0x8
	LONG LockCount;                                   // offset   0x8 size   0x4
	LONG RecursionCount;                              // offset   0xc size   0x4
	PVOID64 OwningThread;                             // offset  0x10 size   0x8
	PVOID64 LockSemaphore;                            // offset  0x18 size   0x8
	ULONGLONG SpinCount;                              // offset  0x20 size   0x8

} __attribute__((packed)) RTL_CRITICAL_SECTION, *PRTL_CRITICAL_SECTION, **PPRTL_CRITICAL_SECTION ;

typedef struct _HEAP_LOCAL_SEGMENT_INFO { // 0xc0 bytes
	PHEAP_SUBSEGMENT Hint;                            // offset   0x0 size   0x8
	PHEAP_SUBSEGMENT ActiveSubsegment;                // offset   0x8 size   0x8
	PHEAP_SUBSEGMENT CachedItems[0x10];               // offset  0x10 size  0x80
	SLIST_HEADER SListHeader;                         // offset  0x90 size  0x10
	HEAP_BUCKET_COUNTERS Counters;                    // offset  0xa0 size   0x8
	volatile PHEAP_LOCAL_DATA LocalData;              // offset  0xa8 size   0x8
	ULONG LastOpSequence;                             // offset  0xb0 size   0x4
	volatile USHORT BucketIndex;                      // offset  0xb4 size   0x2
	USHORT LastUsed;                                  // offset  0xb6 size   0x2
	UINT8 gap_in_pdb_ofs_B8[0x8];                     // offset  0xb8 size   0x8

} __attribute__((packed)) HEAP_LOCAL_SEGMENT_INFO, *PHEAP_LOCAL_SEGMENT_INFO, **PPHEAP_LOCAL_SEGMENT_INFO ;

typedef struct _HEAP_SUBSEGMENT { // 0x30 bytes
	PHEAP_LOCAL_SEGMENT_INFO LocalInfo;               // offset   0x0 size   0x8
	volatile PHEAP_USERDATA_HEADER UserBlocks;        // offset   0x8 size   0x8
	INTERLOCK_SEQ AggregateExchg;                     // offset  0x10 size   0x8
	union {
		struct {
			USHORT BlockSize;                               // offset  0x18 size   0x2
			USHORT Flags;                                   // offset  0x1a size   0x2
			USHORT BlockCount;                              // offset  0x1c size   0x2
			UCHAR SizeIndex;                                // offset  0x1e size   0x1
			UCHAR AffinityIndex;                            // offset  0x1f size   0x1
		};
		ULONG Alignment[0x2];                            // offset  0x18 size   0x8
	};
	SINGLE_LIST_ENTRY SFreeListEntry;                 // offset  0x20 size   0x8
	volatile ULONG Lock;                              // offset  0x28 size   0x4
	UINT8 gap_in_pdb_ofs_2C[0x4];                     // offset  0x2c size   0x4

} __attribute__((packed)) HEAP_SUBSEGMENT, *PHEAP_SUBSEGMENT, **PPHEAP_SUBSEGMENT ;

typedef struct _HEAP_LOCAL_DATA { // 0x6030 bytes
	SLIST_HEADER DeletedSubSegments;                  // offset   0x0 size  0x10
	PLFH_BLOCK_ZONE CrtZone;                          // offset  0x10 size   0x8
	volatile PLFH_HEAP LowFragHeap;                   // offset  0x18 size   0x8
	ULONG Sequence;                                   // offset  0x20 size   0x4
	UINT8 gap_in_pdb_ofs_24[0xc];                     // offset  0x24 size   0xc
	HEAP_LOCAL_SEGMENT_INFO SegmentInfo[0x80];        // offset  0x30 size 0x6000

} __attribute__((packed)) HEAP_LOCAL_DATA, *PHEAP_LOCAL_DATA, **PPHEAP_LOCAL_DATA ;

typedef struct _LFH_HEAP { // 0x6420 bytes
	RTL_CRITICAL_SECTION Lock;                        // offset   0x0 size  0x28
	LIST_ENTRY SubSegmentZones;                       // offset  0x28 size  0x10
	ULONGLONG ZoneBlockSize;                          // offset  0x38 size   0x8
	PVOID64 Heap;                                     // offset  0x40 size   0x8
	ULONG SegmentChange;                              // offset  0x48 size   0x4
	ULONG SegmentCreate;                              // offset  0x4c size   0x4
	ULONG SegmentInsertInFree;                        // offset  0x50 size   0x4
	ULONG SegmentDelete;                              // offset  0x54 size   0x4
	ULONG CacheAllocs;                                // offset  0x58 size   0x4
	ULONG CacheFrees;                                 // offset  0x5c size   0x4
	ULONGLONG SizeInCache;                            // offset  0x60 size   0x8
	HEAP_BUCKET_RUN_INFO RunInfo;                     // offset  0x68 size   0x8
	USER_MEMORY_CACHE_ENTRY UserBlockCache[0xc];      // offset  0x70 size 0x180
	HEAP_BUCKET Buckets[0x80];                        // offset 0x1f0 size 0x200
	HEAP_LOCAL_DATA LocalData[0x1];                   // offset 0x3f0 size 0x6030

} __attribute__((packed)) LFH_HEAP, *PLFH_HEAP, **PPLFH_HEAP ;

typedef struct _HEAP_LOCK { // 0x28 bytes
	union {
	RTL_CRITICAL_SECTION CriticalSection;             // offset   0x0 size  0x28
} Lock; // offset   0x0 size  0x28

} __attribute__((packed)) HEAP_LOCK, *PHEAP_LOCK, **PPHEAP_LOCK ;

typedef struct _HEAP_USERDATA_HEADER { // 0x20 bytes
union {
	SINGLE_LIST_ENTRY SFreeListEntry;                 // offset   0x0 size   0x8
	struct {
		PHEAP_SUBSEGMENT SubSegment;                     // offset   0x0 size   0x8
		PVOID64 Reserved;                                // offset   0x8 size   0x8
		ULONGLONG SizeIndex;                             // offset  0x10 size   0x8
		ULONGLONG Signature;                             // offset  0x18 size   0x8
	};
};
} __attribute__((packed)) HEAP_USERDATA_HEADER, *PHEAP_USERDATA_HEADER, **PPHEAP_USERDATA_HEADER ;

typedef struct _RTL_CRITICAL_SECTION_DEBUG { // 0x30 bytes
	USHORT Type;                                      // offset   0x0 size   0x2
	USHORT CreatorBackTraceIndex;                     // offset   0x2 size   0x2
	UINT8 gap_in_pdb_ofs_4[0x4];                      // offset   0x4 size   0x4
	PRTL_CRITICAL_SECTION CriticalSection;            // offset   0x8 size   0x8
	LIST_ENTRY ProcessLocksList;                      // offset  0x10 size  0x10
	ULONG EntryCount;                                 // offset  0x20 size   0x4
	ULONG ContentionCount;                            // offset  0x24 size   0x4
	ULONG Flags;                                      // offset  0x28 size   0x4
	USHORT CreatorBackTraceIndexHigh;                 // offset  0x2c size   0x2
	USHORT SpareUSHORT;                               // offset  0x2e size   0x2

} __attribute__((packed)) RTL_CRITICAL_SECTION_DEBUG, *PRTL_CRITICAL_SECTION_DEBUG, **PPRTL_CRITICAL_SECTION_DEBUG ;

typedef struct _HEAP { // 0x208 bytes
	HEAP_ENTRY Entry;                                 // offset   0x0 size  0x10
	ULONG SegmentSignature;                           // offset  0x10 size   0x4
	ULONG SegmentFlags;                               // offset  0x14 size   0x4
	LIST_ENTRY SegmentListEntry;                      // offset  0x18 size  0x10
	struct _HEAP*  Heap;                              // offset  0x28 size   0x8
	PVOID64 BaseAddress;                              // offset  0x30 size   0x8
	ULONG NumberOfPages;                              // offset  0x38 size   0x4
	UINT8 gap_in_pdb_ofs_3C[0x4];                     // offset  0x3c size   0x4
	PHEAP_ENTRY FirstEntry;                           // offset  0x40 size   0x8
	PHEAP_ENTRY LastValidEntry;                       // offset  0x48 size   0x8
	ULONG NumberOfUnCommittedPages;                   // offset  0x50 size   0x4
	ULONG NumberOfUnCommittedRanges;                  // offset  0x54 size   0x4
	USHORT SegmentAllocatorBackTraceIndex;            // offset  0x58 size   0x2
	USHORT Reserved;                                  // offset  0x5a size   0x2
	UINT8 gap_in_pdb_ofs_5C[0x4];                     // offset  0x5c size   0x4
	LIST_ENTRY UCRSegmentList;                        // offset  0x60 size  0x10
	ULONG Flags;                                      // offset  0x70 size   0x4
	ULONG ForceFlags;                                 // offset  0x74 size   0x4
	ULONG CompatibilityFlags;                         // offset  0x78 size   0x4
	ULONG EncodeFlagMask;                             // offset  0x7c size   0x4
	HEAP_ENTRY Encoding;                              // offset  0x80 size  0x10
	ULONGLONG PointerKey;                             // offset  0x90 size   0x8
	ULONG Interceptor;                                // offset  0x98 size   0x4
	ULONG VirtualMemoryThreshold;                     // offset  0x9c size   0x4
	ULONG Signature;                                  // offset  0xa0 size   0x4
	UINT8 gap_in_pdb_ofs_A4[0x4];                     // offset  0xa4 size   0x4
	ULONGLONG SegmentReserve;                         // offset  0xa8 size   0x8
	ULONGLONG SegmentCommit;                          // offset  0xb0 size   0x8
	ULONGLONG DeCommitFreeBlockThreshold;             // offset  0xb8 size   0x8
	ULONGLONG DeCommitTotalFreeThreshold;             // offset  0xc0 size   0x8
	ULONGLONG TotalFreeSize;                          // offset  0xc8 size   0x8
	ULONGLONG MaximumAllocationSize;                  // offset  0xd0 size   0x8
	USHORT ProcessHeapsListIndex;                     // offset  0xd8 size   0x2
	USHORT HeaderValidateLength;                      // offset  0xda size   0x2
	UINT8 gap_in_pdb_ofs_DC[0x4];                     // offset  0xdc size   0x4
	PVOID64 HeaderValidateCopy;                       // offset  0xe0 size   0x8
	USHORT NextAvailableTagIndex;                     // offset  0xe8 size   0x2
	USHORT MaximumTagIndex;                           // offset  0xea size   0x2
	UINT8 gap_in_pdb_ofs_EC[0x4];                     // offset  0xec size   0x4
	PHEAP_TAG_ENTRY TagEntries;                       // offset  0xf0 size   0x8
	LIST_ENTRY UCRList;                               // offset  0xf8 size  0x10
	ULONGLONG AlignRound;                             // offset 0x108 size   0x8
	ULONGLONG AlignMask;                              // offset 0x110 size   0x8
	LIST_ENTRY VirtualAllocdBlocks;                   // offset 0x118 size  0x10
	LIST_ENTRY SegmentList;                           // offset 0x128 size  0x10
	USHORT AllocatorBackTraceIndex;                   // offset 0x138 size   0x2
	UINT8 gap_in_pdb_ofs_13A[0x2];                    // offset 0x13a size   0x2
	ULONG NonDedicatedListLength;                     // offset 0x13c size   0x4
	PVOID64 BlocksIndex;                              // offset 0x140 size   0x8
	PVOID64 UCRIndex;                                 // offset 0x148 size   0x8
	PHEAP_PSEUDO_TAG_ENTRY PseudoTagEntries;          // offset 0x150 size   0x8
	LIST_ENTRY FreeLists;                             // offset 0x158 size  0x10
	PHEAP_LOCK LockVariable;                          // offset 0x168 size   0x8
	LONG (*CommitRoutine)(PVOID64, PPVOID64, PULONGLONG); // offset 0x170 size   0x8
	PVOID64 FrontEndHeap;                             // offset 0x178 size   0x8
	USHORT FrontHeapLockCount;                        // offset 0x180 size   0x2
	UCHAR FrontEndHeapType;                           // offset 0x182 size   0x1
	UINT8 gap_in_pdb_ofs_183[0x5];                    // offset 0x183 size   0x5
	HEAP_COUNTERS Counters;                           // offset 0x188 size  0x70
	HEAP_TUNING_PARAMETERS TuningParameters;          // offset 0x1f8 size  0x10

} __attribute__((packed)) HEAP, *PHEAP, **PPHEAP ;


