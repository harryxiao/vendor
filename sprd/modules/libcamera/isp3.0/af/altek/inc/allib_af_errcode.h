/* alAFLib error code */

/* 32 bits wrapper layer begins from 0xCxxxx */
#define ALAF_ERR_CODE 0x0000C000

/*
 * ALAF_ERR_INVALID_INPUT_ARG               49153
 * ALAF_ERR_INVALID_HAF_TYPE                 49154
 * ALAF_ERR_INVALID_PARAM_TYPE             49155
 * ALAF_ERR_LIB_INIT_FAIL                         49156
 * ALAF_ERR_LIB_DESTROY_FAIL                 49157
 * ALAF_ERR_RUNTIME_OBJ_LOST               49158
 * ALAF_ERR_SET_PARAM_LOST                   49159
 * ALAF_ERR_GET_PARAM_LOST                   49160
 * ALAF_ERR_LIB_ERR                                  49161
 * ALAF_ERR_STATS_DATA_LOST                 49162
 * ALAF_ERR_SET_PARAM_UNKOWN            49163
 * ALAF_ERR_INVALID_SENSOR_SIZE          49164
 * ALAF_ERR_INVALID_ISP_IMAGE_SIZE      49165
 */
#define ALAF_ERR_SUCCESS               0x00000000
#define ALAF_ERR_INVALID_INPUT_ARG    	(ALAF_ERR_CODE + 1)
#define ALAF_ERR_INVALID_HAF_TYPE     	(ALAF_ERR_CODE + 2)
#define ALAF_ERR_INVALID_PARAM_TYPE   	(ALAF_ERR_CODE + 3)
#define ALAF_ERR_LIB_INIT_FAIL        		(ALAF_ERR_CODE + 4)
#define ALAF_ERR_LIB_DESTROY_FAIL     	(ALAF_ERR_CODE + 5)
#define ALAF_ERR_RUNTIME_OBJ_LOST     	(ALAF_ERR_CODE + 6)
#define ALAF_ERR_SET_PARAM_LOST        	(ALAF_ERR_CODE + 7)
#define ALAF_ERR_GET_PARAM_LOST        	(ALAF_ERR_CODE + 8)
#define ALAF_ERR_LIB_ERR               		(ALAF_ERR_CODE + 9)
#define ALAF_ERR_STATS_DATA_LOST       	(ALAF_ERR_CODE + 10)
#define ALAF_ERR_SET_PARAM_UNKOWN       	(ALAF_ERR_CODE + 11)
#define ALAF_ERR_INVALID_SENSOR_SIZE    	(ALAF_ERR_CODE + 12)
#define ALAF_ERR_INVALID_ISP_IMAGE_SIZE	(ALAF_ERR_CODE + 13)
#define ALAF_ERR_INVALID_ROI 				(ALAF_ERR_CODE + 14)
#define ALAF_ERR_INVALID_STREAM_CROP_INFO	(ALAF_ERR_CODE + 15)

#define ALAF_PARAM_ERROR  0x000A0000

#pragma pack(push,4)
enum allib_af_param_result_err_list {
	PARAM_ERR_SUCCESS = 0,
	PARAM_ERR_INVALID_INIT_PARAM = 1,
	PARAM_ERR_IMG_LOST = ( 1<< 1),
	PARAM_ERR_UPDATE_MANUAL_POS_DAC_ERR = ( 1 << 2),
	PARAM_ERR_SETTING_FILE_LOST = (1 << 3),
	PARAM_ERR_SETTING_FILE_INCORRECT = (1 << 4),
	PARAM_ERR_INVALID_FOCUS_TYPE = (1 << 5),
	PARAM_ERR_ISP_NO_CHANGE = (1 << 6),
	PARAM_ERR_INVALID_SPECIAL_EVENT = (1 << 7),
	PARAM_ERR_INVALID_IMG_BUFFER = (1 << 8),
	PARAM_ERR_INVALID_MANUAL_DAC  = (1 << 9),
	PARAM_ERR_ROI_NOT_UPDATE = (1 << 10),
	PARAM_ERR_INVALID_HYBRID_TYPE = (1 << 11),
	PARAM_ERR_CANCEL_FOCUS_FAIL = (1 << 12),
	PARAM_ERR_LENSMOVE_TIMEOUT = (1 << 13)
};
#pragma pack(pop)