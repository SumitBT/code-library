package swishtech.api.models;

import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.Table;
import javax.persistence.Temporal;
import javax.persistence.TemporalType;
import javax.validation.constraints.NotNull;
import java.util.Date;

@Entity
@Table(name="schedule")
public class Schedule
{
	@Id
	@GeneratedValue(strategy=GenerationType.AUTO)
	private long scheduleId;
	
	@NotNull
	private long eventId;
	
	@NotNull
	private long subEventId;
	
	@NotNull
	@Column(columnDefinition = "DATETIME")
	@Temporal(TemporalType.TIMESTAMP)
	private Date startTime;

	@NotNull
	@Column(columnDefinition = "DATETIME")
	@Temporal(TemporalType.TIMESTAMP)
	private Date endTime;
	
	@NotNull
	private long venueId;
	
	public Schedule(){}
	
	public Schedule(long eventId, long subEventId, Date startTime, Date endTime, long venueId)
	{
		this.eventId = eventId;
		this.subEventId = subEventId;
		this.startTime = startTime;
		this.endTime = endTime;
		this.venueId = venueId;
	}

	public long getScheduleId()
	{
		return scheduleId;
	}

	public void setScheduleId(long scheduleId)
	{
		this.scheduleId = scheduleId;
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

	public Date getStartTime()
	{
		return startTime;
	}

	public void setStartTime(Date startTime)
	{
		this.startTime = startTime;
	}

	public Date getEndTime()
	{
		return endTime;
	}

	public void setEndTime(Date endTime)
	{
		this.endTime = endTime;
	}

	public long getVenueId()
	{
		return venueId;
	}

	public void setVenueId(long venueId)
	{
		this.venueId = venueId;
	}
	
}