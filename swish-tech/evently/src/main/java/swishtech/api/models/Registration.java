package swishtech.api.models;

import java.util.Date;
import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.Table;
import javax.persistence.Temporal;
import javax.persistence.TemporalType;
import javax.validation.constraints.NotNull;

@Entity
@Table(name="registration")
public class Registration
{
	@Id
	@GeneratedValue(strategy=GenerationType.AUTO)
	private long registrationId;
	
	@NotNull
	private long userId;
	
	@NotNull
	private long eventId;
	
	@NotNull
	private long subEventId;
	
	@NotNull
	@Column(columnDefinition = "DATETIME")
	@Temporal(TemporalType.TIMESTAMP)
	private Date time;
	
	public Registration(){}
	
	public Registration(long userId, long eventId, long subEventId)
	{
		this.userId = userId;
		this.eventId = eventId;
		this.subEventId = subEventId;
	}

	public long getRegistrationId()
	{
		return registrationId;
	}

	public void setRegistrationId(long registrationId)
	{
		this.registrationId = registrationId;
	}

	public long getUserId()
	{
		return userId;
	}

	public void setUserId(long userId)
	{
		this.userId = userId;
	}

	public long getEventId()
	{
		return eventId;
	}

	public void setEventId(long eventId)
	{
		this.eventId = eventId;
	}

	public long getSubEventId()
	{
		return subEventId;
	}

	public void setSubEventId(long subEventId)
	{
		this.subEventId = subEventId;
	}

	public Date getTime()
	{
		return time;
	}

	public void setTime(Date time)
	{
		this.time = time;
	}
	
}
