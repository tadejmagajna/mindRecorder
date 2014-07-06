#include "MyForm.h"
#include "thinkgear.h"
#include <string>
#include <vector>

using namespace System;
using namespace System::Windows::Forms;
connector::connector()
{
}

void connector::device_connect(int n, BackgroundWorker^ worker, DoWorkEventArgs ^ e)
{

	char *comPortName;
	int   dllVersion = 0;
	int   connectionId = 0;
	int   packetsRead = 0;
	int   errCode = 0;


	connectionId = TG_GetNewConnectionId();
	if (connectionId < 0) {
		MessageBox::Show("ERROR: TG_GetNewConnectionId() returned %d.\n");
		return;
	}

	/* Attempt to connect the connection ID handle to serial port "COM5" */
	comPortName = "\\\\.\\COM3";
	errCode = TG_Connect(connectionId,
		comPortName,
		TG_BAUD_1200,
		TG_STREAM_PACKETS);
	if (errCode < 0) {
		MessageBox::Show("Povezava neuspešna.\n");
		return;
	}

	/* Read 10 ThinkGear Packets from the connection, 1 Packet at a time */
	packetsRead = 0;

	array<int>^ data = gcnew array<int>(9);
	int remember = -1;

	while (true) {

		/* Attempt to read a Packet of data from the connection */
		errCode = TG_ReadPackets(connectionId, 1);

		/* If TG_ReadPackets() was able to read a complete Packet of data... */
		if (errCode == 1) {

			if (worker->CancellationPending)
			{
				TG_Disconnect(connectionId);
				return;
			}
			
			/* If attention value has been updated by TG_ReadPackets()... */
			if (TG_GetValueStatus(connectionId, TG_DATA_ALPHA1) != 0)
				data[0] = (int)TG_GetValue(connectionId, TG_DATA_ALPHA1);
			if (TG_GetValueStatus(connectionId, TG_DATA_ALPHA2) != 0)
				data[1] = (int)TG_GetValue(connectionId, TG_DATA_ALPHA2);
			if (TG_GetValueStatus(connectionId, TG_DATA_BETA1) != 0)
				data[2] = (int)TG_GetValue(connectionId, TG_DATA_BETA1);
			if (TG_GetValueStatus(connectionId, TG_DATA_BETA2) != 0)
				data[3] = (int)TG_GetValue(connectionId, TG_DATA_BETA2);
			if (TG_GetValueStatus(connectionId, TG_DATA_GAMMA1) != 0)
				data[4] = (int)TG_GetValue(connectionId, TG_DATA_GAMMA1);
			if (TG_GetValueStatus(connectionId, TG_DATA_GAMMA2) != 0)
				data[5] = (int)TG_GetValue(connectionId, TG_DATA_GAMMA2);
			if (TG_GetValueStatus(connectionId, TG_DATA_DELTA) != 0)
				data[6] = (int)TG_GetValue(connectionId, TG_DATA_DELTA);
			if (TG_GetValueStatus(connectionId, TG_DATA_THETA) != 0)
				data[7] = (int)TG_GetValue(connectionId, TG_DATA_THETA);
			if (TG_GetValueStatus(connectionId, TG_DATA_POOR_SIGNAL) != 0)
				data[8] = (int)TG_GetValue(connectionId, TG_DATA_POOR_SIGNAL);

			
			if (remember == data[0] + data[1] + data[2] + data[3])
				continue;


			
			//if quality is not 100%
			if (data[8] == 0 && data[0] != 0)
				worker->ReportProgress(100, data);
			else if(data[0] != 0)
				worker->ReportProgress(0, data);
				
			remember = data[0] + data[1] + data[2] + data[3];
			

			

		} /* end "If a Packet of data was read..." */

	} /* end "Read 10 Packets of data from connection..." */
}
