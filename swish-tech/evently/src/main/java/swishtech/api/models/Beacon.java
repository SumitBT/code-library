package swishtech.api.models;

import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.Table;
import javax.validation.constraints.NotNull;

@Entity
@Table(name="beacon")
public class Beacon
{

	@Id
	@GeneratedValue(strategy=GenerationType.AUTO)
	private long beaconId;

	@NotNull
	private String deviceId;

	@NotNull
	private String instanceId;

	public Beacon(){}
	
	public Beacon(String deviceId, String instanceId)
	{
		this.deviceId = deviceId;
		this.instanceId = instanceId;
	}

	public long getBeaconId()
	{
		return beaconId;
	}

	public void setBeaconId(long beaconId)
	{
		this.beaconId = beaconId;
	}

	public String getDeviceId()
	{
		return deviceId;
	}

	public void setDeviceId(String deviceId)
	{
		this.deviceId = deviceId;
	}

	public String getInstanceId()
	{
		return instanceId;
	}

	public void setInstanceId(String instanceId)
	{
		this.instanceId = instanceId;
	}
	
}