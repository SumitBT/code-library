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
@Table(name="sub_event")
public class SubEvent
{
	@Id
	@GeneratedValue(strategy=GenerationType.AUTO)
	private long subEventId;

	@NotNull
	private long eventId;
	
	@NotNull
	private String name;
	
	@NotNull
	private String description;
	
	@NotNull
	private long capacity;
	
	@NotNull
	private long totalRegistration;
	
	@NotNull
	@Column(columnDefinition = "DATETIME")
	@Temporal(TemporalType.TIMESTAMP)
	private Date deadline;

	public SubEvent(){}
	
	public SubEvent(long eventId, String name, String description, long capacity, Date deadline)
	{
		this.eventId = eventId;
		this.name = name;
		this.description = description;
		this.capacity = capacity;
		this.deadline = deadline;
	}

	public long getSubEventId()
	{
		return subEventId;
	}

	public void setSubEventId(long subEventId)
	{
		this.subEventId = subEventId;
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

	public String getDescription()
	{
		return description;
	}

	public void setDescription(String description)
	{
		this.description = description;
	}

	public long getCapacity()
	{
		return capacity;
	}

	public void setCapacity(long capacity)
	{
		this.capacity = capacity;
	}

	public long getTotalRegistration()
	{
		return totalRegistration;
	}

	public void setTotalRegistration(long totalRegistration)
	{
		this.totalRegistration = totalRegistration;
	}

	public Date getDeadline()
	{
		return deadline;
	}

	public void setDeadline(Date deadline)
	{
		this.deadline = deadline;
	}
	
}