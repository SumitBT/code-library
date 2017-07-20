package swishtech.api.models;

import java.util.Date;
import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.Table;
import javax.validation.constraints.NotNull;

@Entity
@Table(name="event")
public class Event
{
	@Id
	@GeneratedValue(strategy=GenerationType.AUTO)
	private long eventId;
	
	@NotNull
	private String name;
	
	@NotNull
	private long accountId;
	
	@NotNull
	private Date startDt;
	
	@NotNull
	private Date endDt;
	
	@NotNull
	private String description;
	
	@NotNull
	private String location;
	
	@NotNull
	private long adminId;
	
	public Event(){}
	
	public Event(String name, long accountId, Date startDt, Date endDt, String description, String location)
	{
		this.name = name;
		this.accountId = accountId;
		this.startDt = startDt;
		this.endDt = endDt;
		this.description = description;
		this.location = location;
	}

	public long getEventId()
	{
		return eventId;
	}

	public void setEventId(long eventId)
	{
		this.eventId = eventId;
	}

	public String getName()
	{
		return name;
	}

	public void setName(String name)
	{
		this.name = name;
	}

	public long getAccountId()
	{
		return accountId;
	}

	public void setAccountId(long accountId)
	{
		this.accountId = accountId;
	}

	public Date getStartDt()
	{
		return startDt;
	}

	public void setStartDt(Date startDt)
	{
		this.startDt = startDt;
	}

	public Date getEndDt()
	{
		return endDt;
	}

	public void setEndDt(Date endDt)
	{
		this.endDt = endDt;
	}

	public String getDescription()
	{
		return description;
	}

	public void setDescription(String description)
	{
		this.description = description;
	}

	public String getLocation()
	{
		return location;
	}

	public void setLocation(String location)
	{
		this.location = location;
	}

	public long getAdminId()
	{
		return adminId;
	}

	public void setAdminId(long adminId)
	{
		this.adminId = adminId;
	}

}