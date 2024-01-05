#include "btstack_defines.h"
#include "btstack_run_loop.h"
#include "bluetooth.h"

#define ADC_CHANNEL_TEMPSENSOR 4
#define HEARTBEAT_PERIOD_MS 1000

extern int le_notification_enabled;
extern hci_con_handle_t con_handle;
extern uint16_t current_temp;
extern uint8_t const profile_data[];

void packet_handler(uint8_t packet_type, uint16_t channel, uint8_t *packet, uint16_t size);
uint16_t att_read_callback(hci_con_handle_t connection_handle, uint16_t att_handle, uint16_t offset, uint8_t * buffer, uint16_t buffer_size);
int att_write_callback(hci_con_handle_t connection_handle, uint16_t att_handle, uint16_t transaction_mode, uint16_t offset, uint8_t *buffer, uint16_t buffer_size);
void poll_temp(void);





static btstack_timer_source_t heartbeat;
static btstack_packet_callback_registration_t hci_event_callback_registration;

static void heartbeat_handler(struct btstack_timer_source *ts);


